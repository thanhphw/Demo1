#include <iostream>
#include <GL/Glut.h> 
#include <cstdlib>
using namespace std;

class hinhhoc{
private:
    float colorR, colorG, colorB;
    int ToaDoDiemVeX;
    int ToaDoDiemVeY;
public:
    hinhhoc();
    ~hinhhoc();
    virtual void NhapRGB();
    virtual void NhapToaDoDiemVe();
    float GetR();
    float GetG();
    float GetB();
    int GetToaDoDiemVeX();
    int GetToaDoDiemVeY();
};
 
hinhhoc::hinhhoc(){
    this->colorR = 0;
    this->colorG = 0;
    this->colorB = 0;
    this->ToaDoDiemVeX = 0;
    this->ToaDoDiemVeY = 0;
}

hinhhoc::~hinhhoc(){}

void hinhhoc::NhapRGB(){
    cout << "Nhap mau thu 1(0->1):"; cin >> this->colorR;
    cout << "Nhap mau thu 2(0->1):"; cin >> this->colorG;
    cout << "Nhap mau thu 3(0->1):"; cin >> this->colorB;
}

void hinhhoc::NhapToaDoDiemVe(){
    cout << "Nhap toa do x: "; cin >> this->ToaDoDiemVeX;
    cout << "Nhap toa do y: "; cin >> this->ToaDoDiemVeY;
}

float hinhhoc::GetR(){
    return colorR;
}

float hinhhoc::GetG(){
    return colorG;
}

float hinhhoc::GetB(){
    return colorB;
}

int hinhhoc::GetToaDoDiemVeX(){
    return ToaDoDiemVeX;
}

int hinhhoc::GetToaDoDiemVeY(){
    return ToaDoDiemVeY;
}

class diem {
private:
    short diemx;
    short diemy;
public:
    diem();
    ~diem();
    void NhapDiem();
    short Getdiemx();
    short Getdiemy();
};

diem::diem(){
    diemx = 0;
    diemy = 0;
}

diem::~diem(){}
short diem::Getdiemx(){
    return diemx;
}
short diem::Getdiemy(){
    return diemy;
}
void diem::NhapDiem(){
    cout << "Nhap toa do x: "; cin >> diemx;
    cout << "Nhap toa do y: "; cin >> diemy;
}
class dagiac;
class duongthang : public hinhhoc{
protected:
    short sodiem;
    diem toadocacdiem[10];
public:
    duongthang();
    ~duongthang();
    void NhapDiem();
    short GetSoDiem();
    short GetTatCaX1(int i);
    short GetTatCaY1(int i); 
};
duongthang::duongthang(){
    this->sodiem = 2;
    toadocacdiem[this->sodiem];
}

duongthang::~duongthang(){}

void duongthang::NhapDiem(){
    toadocacdiem[this->sodiem];
    for (int i = 0; i < this->sodiem; i++){
        toadocacdiem[i].NhapDiem();
    }
}

short duongthang::GetSoDiem(){
    return this->sodiem;
}
short duongthang::GetTatCaX1(int i){
    return toadocacdiem[i].Getdiemx();
}

short duongthang::GetTatCaY1(int i){
    return toadocacdiem[i].Getdiemy();
}

class hinhchunhat : public hinhhoc{
private:
    short chieudai, chieurong;
public:
    hinhchunhat();
    ~hinhchunhat();
    void Nhaphinhchunhat();
    short GetChieuDai();
    short GetChieuRong();
    friend void XuatToaDoVoiHinhChuNhat(dagiac a, hinhchunhat b);
};

short hinhchunhat::GetChieuDai(){
    return chieudai;
}
short hinhchunhat::GetChieuRong(){
    return chieurong;
}

hinhchunhat::hinhchunhat(){
    this->chieudai = 0;
    this->chieurong = 0;
}

hinhchunhat::~hinhchunhat(){}

void hinhchunhat::Nhaphinhchunhat(){
    cout << "Nhap chieu dai hinh chu nhat: ";
    cin >> chieudai;
    cout << "Nhap chieu rong hinh chu nhat: ";
    cin >> chieurong;
}

class hinhvuong : public hinhhoc{
private:
    short chieudaicanh;
public:
    hinhvuong();
    ~hinhvuong();
    void NhapChieuDaiCanh();
    short GetChieuDaiCanh();
};

short hinhvuong::GetChieuDaiCanh(){
        return chieudaicanh;
}
hinhvuong::hinhvuong(){
    this->chieudaicanh = 0;
}

hinhvuong::~hinhvuong(){}

void hinhvuong::NhapChieuDaiCanh(){
    cout << "Nhap chieu dai canh hinh vuong: ";
    cin >> this->chieudaicanh;
}

class hinhtron : public hinhhoc{
private:
    short bankinh;
public:
    hinhtron();
    ~hinhtron();
    void NhapBanKinh();
    short GetBanKinh();
};

hinhtron::hinhtron(){
    this->bankinh = 0;
}

hinhtron::~hinhtron(){}

void hinhtron::NhapBanKinh(){
    cout << "Nhap ban kinh cho duong tron: "; cin >> this->bankinh;
}

short hinhtron::GetBanKinh(){
    return bankinh;
}

class dagiac : public hinhhoc{
protected:
    short sodiem;
    diem toadocacdiem[10];
public:
    dagiac();
    ~dagiac();
    void NhapSoDiem();
    void NhapDiemChoHinhCoSanSoDiem(short sodiemcosan);
    short GetSoDiem();
    short GetTatCaX(int i);
    short GetTatCaY(int i); 
    friend void XuatToaDoVoiHinhChuNhat(dagiac a, hinhchunhat b);
};

dagiac::dagiac(){
    this->sodiem  = 0;
    toadocacdiem[this->sodiem];
}

dagiac::~dagiac(){}

void dagiac::NhapSoDiem(){
    cout << "Nhap so canh cua da giac:"; cin >> this->sodiem;
    toadocacdiem[this->sodiem];
    for (int i = 0; i < this->sodiem; i++){
        toadocacdiem[i].NhapDiem();
    }
}

void dagiac::NhapDiemChoHinhCoSanSoDiem(short sodiemcosan){
    toadocacdiem[sodiemcosan];
    for (int i = 0; i < sodiemcosan; i++){
        toadocacdiem[i].NhapDiem();
    }
}

short dagiac::GetSoDiem(){
    return this->sodiem;
}
short dagiac::GetTatCaX(int i){
    return toadocacdiem[i].Getdiemx();
}

short dagiac::GetTatCaY(int i){
    return toadocacdiem[i].Getdiemy();
}

void XuatToaDoVoiHinhChuNhat(dagiac a, hinhchunhat b){
    cout << "Toa do cua cac dinh cua da giac A la: \n";
    for (int i = 0; i < a.sodiem; i++){
        short tempx, tempy;
        tempx = a.GetTatCaX(i);
        tempy = a.GetTatCaY(i);
        cout << "Toa do diem x thu " << i + 1 << " la :" << tempx << endl;
        cout << "Toa do diem y thu " << i + 1 << " la :" << tempy << endl;
    }
    cout << endl << "Chieu dai va rong cua hinh chu nhat lan luot la" << b.GetChieuDai() << ", " << b.GetChieuRong() << endl;
}

void InitGL(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glOrtho(-320,320,-240,240,-1,1);
}

void grid();
void NOTIFY(int st);
void TrucToaDo();

int LuaChonBatTat(){
    NOTIFY(8);
    int luachon;
    cin >> luachon;
    return luachon;
}

void LuaChonCheDo(int luachonbattat){
    if (luachonbattat == 1) {
        TrucToaDo();
    } else if (luachonbattat == 2){
        grid();
    }
}

void drawduongthang(duongthang AB, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    glColor3f(0.0f, 0.0f, 0.0f);
    glViewport(0, 0 ,640,480);
    glBegin(GL_LINES);
    for (int i = 0; i < 2; i++){
        short tempx1, tempy1;
        tempx1 = AB.GetTatCaX1(i);
        tempy1 = AB.GetTatCaY1(i);
    	glVertex2f(tempx1, tempy1);   
    	//glVertex2f(Bx, By);
    }
 	glEnd();	
  	glFlush();
}

void drawduongthang(duongthang AB, float R, float G, float B, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    glColor3f(R, G, B);
    glViewport(0, 0 ,640,480);
    glBegin(GL_LINES);
    for (int i = 0; i < 2; i++){
        short tempx1, tempy1;
        tempx1 = AB.GetTatCaX1(i);
        tempy1 = AB.GetTatCaY1(i);
    	glVertex2f(tempx1, tempy1);   
    }
 	glEnd();	
  	glFlush();
}


void drawchunhat(short chieudai, short chieurong, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    glColor3f(0.0f, 0.0f, 0.0f);
    glViewport(0, 0 ,640,480);
    glBegin(GL_POLYGON);
    	glVertex2f(-chieudai/2, chieurong/2);   
    	glVertex2f(chieudai/2, chieurong/2);
    	glVertex2f(chieudai/2, -chieurong/2);
    	glVertex2f(-chieudai/2,  -chieurong/2);
 	glEnd();	
  	glFlush();
}

void drawchunhat(short chieudai, short chieurong, float R, float G, float B, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    glColor3f(R, G, B);
    glViewport(0, 0 ,640,480);
    glBegin(GL_POLYGON);
    	glVertex2f(-chieudai/2, chieurong/2);   
    	glVertex2f(chieudai/2, chieurong/2);
    	glVertex2f(chieudai/2, -chieurong/2);
    	glVertex2f(-chieudai/2,  -chieurong/2);
 	glEnd();	
  	glFlush();
}

void drawhinhvuong(short chieudai, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    //cout << " thao tac 1\n\n";
    glColor3f(0.0f, 0.0f, 0.0f);
    glViewport(0, 0 ,640,480);
    glBegin(GL_POLYGON);
    	glVertex2f(-chieudai/2, chieudai/2);   
    	glVertex2f(chieudai/2, chieudai/2);
    	glVertex2f(chieudai/2, -chieudai/2);
    	glVertex2f(-chieudai/2,  -chieudai/2);
    glEnd();	
  	glFlush();
}

void drawhinhvuong(short chieudai, float R, float G, float B, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    glColor3f(R, G, B);
    glViewport(0, 0 ,640,480);
    glBegin(GL_POLYGON);
    		glVertex2f(-chieudai/2, chieudai/2);   
    		glVertex2f(chieudai/2, chieudai/2);
    		glVertex2f(chieudai/2, -chieudai/2);
    		glVertex2f(-chieudai/2,  -chieudai/2);
 	glEnd();	
  	glFlush();
}

void draw8point(int xc, int yc, int x, int y){
	glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - y, yc - x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc - x, yc + y);
	glEnd();
}

void CircleMidpoint(int xc,int yc,int R)	
{	 
   	float P;
	int y = R; 
	int x = 0;
	P = 5/4 - R;
	draw8point(xc,yc,x,y);
	while (x < y) {
		if (P <0)	
            {
			P += 2*x + 3;
            }
        else     
            {	
            P += 2*(x - y) + 5;
            y--;
	        }
		x++;
        draw8point(xc,yc,x,y);
	}
}

void drawtugiac(short sodiem, dagiac a, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    glColor3f(0.0f, 0.0f, 0.0f);
    glViewport(0, 0 ,640,480);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sodiem - 1; i++){
        short tempx, tempy, tempx1, tempy1;
        tempx = a.GetTatCaX(i);
        tempy = a.GetTatCaY(i);
        tempx1 = a.GetTatCaX(i+1);
        tempy1 = a.GetTatCaY(i+1);
            glVertex2f(tempx, tempy);
            glVertex2f(tempx1, tempy1);   
        //cout << tempx << endl << tempy << endl;
    }
    glEnd();	
    glFlush();
}

void drawtugiac(short sodiem, dagiac a, float R, float G, float B, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    glColor3f(R, G, B);
    glViewport(0, 0 ,640,480);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sodiem - 1; i++){
        short tempx, tempy, tempx1, tempy1;
        tempx = a.GetTatCaX(i);
        tempy = a.GetTatCaY(i);
        tempx1 = a.GetTatCaX(i+1);
        tempy1 = a.GetTatCaY(i+1);
        
            glVertex2f(tempx, tempy);
            glVertex2f(tempx1, tempy1);   
        //cout << tempx << endl << tempy << endl;
    }
    glEnd();	
    glFlush();
}
void TrucToaDo(){
    glColor3f(1.0f, 0.0f, 0.0f); 
	glViewport(0, 0 ,640,480);    
    glBegin(GL_LINES);
	    glVertex2f(0, -480);  
	    glVertex2f(0, 480);     
	    glVertex2f(-640, 0);  
	    glVertex2f(640, 0);      
    glEnd();	
	glFlush();
}
void grid(){
    glColor3f(0.41, 0.41, 0.41); 
	glViewport(0, 0 ,640,480);    
    glBegin(GL_LINES);
    bool red = false;
    for (int i = -700; i <= 700; i += 100){  
	    glVertex2f(i, -480);  
	    glVertex2f(i, 480);
	}
	for (int i = -500; i <= 500; i += 100){	
        glVertex2f(-640, i);  
	    glVertex2f(640, i);       
	}
    glEnd();	
	glFlush();
    TrucToaDo();
}

void mydisplayhinhtron(short bankinh, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    //glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	CircleMidpoint(0, 0, bankinh); 
	glViewport(0,0,640,480);
	glFlush();
}

void mydisplayhinhtron(short bankinh, float R, float G, float B, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    //glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(R, G, B);
	CircleMidpoint(0, 0, bankinh);  
	glViewport(0,0,640,480);
	glFlush();
}

void mydisplayhinhtron(short bankinh, int toadox, int toadoy, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    //glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	CircleMidpoint(toadox, toadoy, bankinh); 
	glViewport(0,0,640,480);
	glFlush();
}

void mydisplayhinhtron(short bankinh, float R, float G, float B, int toadox, int toadoy, int luachonbattat){
    LuaChonCheDo(luachonbattat);
    //glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(R, G, B);
	CircleMidpoint(toadox, toadoy, bankinh); 
	glViewport(0,0,640,480);
	glFlush();
}

bool BatGrid(){
	return true;
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);         
    NOTIFY(1);
    int luachon; cin >> luachon;
    if (luachon == 1) {
        NOTIFY(6);
        int luachonve; cin >> luachonve;
        if (luachonve == 1) {
            hinhchunhat ABCD;
            NOTIFY(0);
            ABCD.Nhaphinhchunhat();
            short chieudai1 = ABCD.GetChieuDai();
            short chieurong1 = ABCD.GetChieuRong();
            NOTIFY(2);
            int luachonrgb; cin >> luachonrgb;
            if (luachonrgb == 1){
                ABCD.NhapRGB();
                float R = ABCD.GetR();
                float G = ABCD.GetG();
                float B = ABCD.GetB();
                int luachonbattat = LuaChonBatTat();
                drawchunhat(chieudai1 ,chieurong1, R, G, B, 2);   	
            } else {
                int luachonbattat = LuaChonBatTat();
                drawchunhat(chieudai1 ,chieurong1, luachonbattat);
            }
        } else {
            dagiac a;
            NOTIFY(0);
            a.NhapDiemChoHinhCoSanSoDiem(4);
            NOTIFY(2);
            int luachonrgb; cin >> luachonrgb;
            if (luachonrgb == 1){
                a.NhapRGB();
                float R = a.GetR();
                float G = a.GetG();
                float B = a.GetB();
                int luachonbattat = LuaChonBatTat();
                drawtugiac(4, a, R, G, B, luachonbattat);
            } else {
                int luachonbattat = LuaChonBatTat();
                drawtugiac(4, a, luachonbattat);
            }
        }
    } else if (luachon == 2) {
        NOTIFY(6);
        int luachonve; cin >> luachonve;
        if (luachonve == 1) {
            hinhvuong MNPQ;
            NOTIFY(0);
            MNPQ.NhapChieuDaiCanh();
            short chieudaicanh1 = MNPQ.GetChieuDaiCanh();
            NOTIFY(2);
            int luachonrgb; cin >> luachonrgb;
            if (luachonrgb == 1){
                MNPQ.NhapRGB();
                float R = MNPQ.GetR();
                float G = MNPQ.GetG();
                float B = MNPQ.GetB();
                int luachonbattat = LuaChonBatTat();
                drawhinhvuong(chieudaicanh1, R, G, B, luachonbattat);
            } else {
                int luachonbattat = LuaChonBatTat();
                drawhinhvuong(chieudaicanh1, luachonbattat);
            }
        } else {
            dagiac a;
            NOTIFY(0);
            a.NhapDiemChoHinhCoSanSoDiem(4);
            NOTIFY(2);
            int luachonrgb; cin >> luachonrgb;
            if (luachonrgb == 1){
                a.NhapRGB();
                float R = a.GetR();
                float G = a.GetG();
                float B = a.GetB();
                int luachonbattat = LuaChonBatTat();
                drawtugiac(4, a, R, G, B, luachonbattat);
            } else {
                int luachonbattat = LuaChonBatTat();
                drawtugiac(4, a, luachonbattat);
            }
        }    
    } else if (luachon == 3) {
        duongthang AB;
        NOTIFY(0);
        AB.NhapDiem();
        NOTIFY(2);
        int luachonrgb; cin >> luachonrgb;
        if (luachonrgb == 1){
            AB.NhapRGB();
            float R = AB.GetR();
            float G = AB.GetG();
            float B = AB.GetB();
            int luachonbattat = LuaChonBatTat();
            drawduongthang(AB, R, G, B, luachonbattat);
        } else {
            int luachonbattat = LuaChonBatTat();
            drawduongthang(AB, luachonbattat);
        }
    } else if (luachon == 4) {
        NOTIFY(7);
        int luachonvetam; cin >> luachonvetam;
        if (luachonvetam == 1) {
            hinhtron OAX;
            NOTIFY(0);
            OAX.NhapBanKinh();
            short bankinh1 = OAX.GetBanKinh();
            NOTIFY(2);
            int luachonrgb; cin >> luachonrgb;
            if (luachonrgb == 1){
                OAX.NhapRGB();
                float R = OAX.GetR();
                float G = OAX.GetG();
                float B = OAX.GetB();
                int luachonbattat = LuaChonBatTat();
                mydisplayhinhtron(bankinh1, R, G, B, luachonbattat);
            } else {
                int luachonbattat = LuaChonBatTat();
                mydisplayhinhtron(bankinh1, luachonbattat);
            }
        } else {
            hinhtron OAX;
            NOTIFY(0);
            OAX.NhapToaDoDiemVe();
            int temptoadox = OAX.GetToaDoDiemVeX();
            int temptoadoy = OAX.GetToaDoDiemVeY();
            OAX.NhapBanKinh();
            short bankinh1 = OAX.GetBanKinh();
            NOTIFY(2);
            int luachonrgb; cin >> luachonrgb;
            if (luachonrgb == 1){
                OAX.NhapRGB();
                float R = OAX.GetR();
                float G = OAX.GetG();
                float B = OAX.GetB();
                int luachonbattat = LuaChonBatTat();
                mydisplayhinhtron(bankinh1, R, G, B, temptoadox, temptoadoy, luachonbattat);
            } else {
                int luachonbattat = LuaChonBatTat();
                mydisplayhinhtron(bankinh1, temptoadox, temptoadoy, luachonbattat);
            }
        }
    } else if (luachon == 5) {
        dagiac a;
        a.NhapSoDiem();
        short sodiem1 = a.GetSoDiem();
        NOTIFY(2);
        int luachonrgb; cin >> luachonrgb;
        if (luachonrgb == 1){
            a.NhapRGB();
            float R = a.GetR();
            float G = a.GetG();
            float B = a.GetB();
            int luachonbattat = LuaChonBatTat();
            drawtugiac(sodiem1, a, R, G, B, luachonbattat);
        } else {
            int luachonbattat = LuaChonBatTat();
            drawtugiac(sodiem1, a, luachonbattat);
        }
    } else if (luachon == 6){
        grid();
    } else if (luachon == 7){
        TrucToaDo();
    } 
}

void mydisplay1(){
  	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f); 
	glViewport(0, 0 ,640,480);
	glBegin(GL_POLYGON);
    	glVertex2f(-0.5f, -0.5f);  
    	glVertex2f( 0.5f, -0.5f);
    	glVertex2f( 0.5f,  0.5f);
    	glVertex2f(-0.5f,  0.5f);
 	glEnd();	
  	glFlush();
}
void mydisplaydelete(){
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	glViewport(0,0,640,480);
	glFlush();
}
int GLUT(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(1200,200);
    glutCreateWindow("Ve Cac Doi Tuong Hinh Hoc");
    glutDisplayFunc(mydisplay);
    InitGL();
    glutMainLoop();
}

void NOTIFY(int st){
	system("cls");
    if (st == 1) cout << "Ban muon ve hinh nao:\n1. Hinh chu nhat\n2. Hinh vuong\n3. Duong thang\n4. Duong tron\n5. Da giac\n6. Ve luoi\n7. Ve truc toa do\n\n";
    if (st == 2) cout << "Ban co muon to mau cho hinh ve khong:\n1. Co\n2. Khong\n";
    if (st == 3) cout << "Lua chon cac thao tac sau day:\n1. Ve Cac Doi Tuong Hinh Hoc\n2. Xoa tat ca hinh da ve\n3. Ket thuc\n\n";
    if (st == 4) cout << "Da xoa cac doi tuong hinh hoc!\n\n";
    if (st == 5) cout << "Ban da chon thoat chuong trinh";
    if (st == 6) cout << "Ban muon ve bang chieu dai canh hay toa do cac dinh:\n1. Chieu dai canh\n2. Toa do cac dinh\n\n";
    if (st == 7) cout << "Ban muon ve duong tron voi tam:\n1. (0;0)\n2. Nhap tu ban phim\n\n";
    if (st == 8) cout << "Ban co muon bat tat truc toa do hay luoi khong?\n1. Truc toa do\n2. Luoi\n3. Khong\n\n";
}

int main(int argc, char** argv){
    GLUT(argc, argv);
}