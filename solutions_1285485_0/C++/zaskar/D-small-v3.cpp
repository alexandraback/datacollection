#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

// 5 6 24 da 66 y 22

#define TOL 1e-4
#define EQUAL(a,b) ((a)-(b)<TOL && (b)-(a)<TOL)
#define TOL2 1e-5
#define EQUAL2(a,b) ((a)-(b)<TOL2 && (b)-(a)<TOL2)
#define LESS(a,b) ((a)<(b)+TOL)
#define TOL3 1e-4
#define LESS3(a,b) ((a)<(b)+TOL3)

#define MAXW 10000
#define POW 21
double where[MAXW][2];
int wc=0;

bool test(bool M[][50], double tx, double ty, int i, int j, double x, double y, double dx, double dy, double d, bool first=false) {
	
	if (LESS(d,0)) return false;
	// ver si llego de vuelta a la X
	if (!first && EQUAL(i+.5,ty) && EQUAL(j+.5,tx)) { // no esta saliendo
		if (EQUAL(dx,0)) {
			return (LESS(0,dx) && LESS3( (x-tx)*(x-tx)+(y-ty)*(y-ty) , d*d ));
		} else if (EQUAL(dy,0)) {
			return (LESS(0,dy) && LESS3( (x-tx)*(x-tx)+(y-ty)*(y-ty) , d*d ));
		} else {
			double rx=(tx-x)/dx;
			if (LESS(0,rx)) {  // distancia a la X positiva
				double ry=EQUAL(dy,0)?0:(ty-y)/dy;
				if (EQUAL(rx,ry)) // razones iguales para x e y
					return (LESS3( (x-tx)*(x-tx)+(y-ty)*(y-ty) , d*d ));
			}
		}
	}
	
	if (EQUAL(dx,0)) {
		if (LESS(dy,0)) {
			d-=(y-i); y=i; 
			if (M[i-1][j]) {
				where[wc][0]=x; where[wc++][1]=y;
				dy=-dy;
			} else {
				i--;
			}
		} else {
			d-=((i+1)-y); y=i+1;
			if (M[i+1][j]) {
				where[wc][0]=x; where[wc++][1]=y;
				dy=-dy;
			} else {
				i++; 
			}
		}
		return test(M,tx,ty,i,j,x,y,dx,dy,d/*,fi,fj*/);
		
	} else if (EQUAL(dy,0)) {
		if (LESS(dx,0)) {
			d-=(x-j); x=j;
			if (M[i][j-1]) {
				where[wc][0]=x; where[wc++][1]=y;
				dx=-dx;
			} else {
				j--;
			}
		} else {
			d-=((j+1)-x); x=(j+1);
			if (M[i][j+1]) {
				where[wc][0]=x; where[wc++][1]=y;
				dx=-dx;
			} else {
				j++;
			}
		}
		return test(M,tx,ty,i,j,x,y,dx,dy,d/*,fi,fj*/);
	} else {
		
		double rx,ry; int ti,tj;
		if (dx>0) { rx=(j+1-x)/dx; tj=j+1; } else { rx=(j-x)/dx; tj=j-1; }
		if (dy>0) { ry=(i+1-y)/dy; ti=i+1; } else { ry=(i-y)/dy; ti=i-1; }
		if (EQUAL(rx,ry)) { // va a la esquina una esquina
			if (dx<0) x=j; else x=j+1;
			if (dy<0) y=i; else y=i+1;
			d-=rx;
			if (M[ti][tj]) { // hay espejo en esa esquina
				if (!M[ti][j] && !M[i][tj]) return false; // si esta solo, absorbe
				where[wc][0]=x; where[wc++][1]=y;
				if (M[ti][j] && M[i][tj]) { // si esta en una concavidad rebota
					dx=-dx; dy=-dy;
				} else if (M[ti][j]) {
					dy=-dy; j=tj;
				} else /*(M[i][tj])*/ {
					dx=-dx; i=ti;
				}
			} else {
				if (dy<0) i--; else i++;
				if (dx<0) j--; else j++;
			} // si no hay espejo ya esta todo hecho
		} else {
			if (rx<ry) {
				if (dx<0) x=j; else x=j+1;
				y+=dy*rx; d-=rx;
				if (M[i][tj]) {
					where[wc][0]=x; where[wc++][1]=y;
					dx=-dx; 
				} else j=tj;
			} else {
				if (dy<0) y=i; else y=i+1;
				x+=dx*ry; d-=ry;
				if (M[ti][j]) {
					where[wc][0]=x; where[wc++][1]=y;
					dy=-dy; 
				} else i=ti;
			}
		}
		
		return test(M,tx,ty,i,j,x,y,dx,dy,d/*,fi,fj*/);
		
	}
	
	return false;
}

int main(int argc, char *argv[]) {
	ifstream fin("D-small-attempt2.in");
//	ifstream fin("D-sample.in");
	ofstream fout("D-small-attempt2.out");
//	ofstream fout("D-sample.out");
	int C; fin>>C;
	bool M[50][50]; 
	for(int c=0;c<C;c++) {
		int r=0,h,w,d,i0,j0;
		fin>>h>>w>>d; char aux;
		cerr<<c+1<<" "<<w<<" "<<h<<" "<<d<<endl;
		for(int i=0;i<h;i++) { 
			for(int j=0;j<w;j++) { 
				fin>>aux;
				M[i][j]=aux=='#';
				if (aux=='X') { i0=i; j0=j; }
			}
		}
		
		int max=pow(2,POW); wc=0;
		for(int i=0;i<max;i++) { 
				int lw=wc;
//				double f=double(rand())/RAND_MAX;
				double f=M_PI*2*i/max;
				double cx=cos(f), cy=sin(f);
				if (EQUAL(cx,0)) { cx=0; cy=cy<0?-1:1; }
				else if (EQUAL(cy,0)) { cy=0; cx=cx<0?-1:1; }
				else if (EQUAL(cx,cy)) { if (cy*cx>0) cx=cy; else cx=-cy; }
				if (test(M,j0+.5,i0+.5, i0,j0, j0+.5,i0+.5, cx,cy,d,true)) {
					r++;
					where[lw][0]=where[wc-1][0]; where[lw][1]=where[wc-1][1]; wc=lw+1;
				} else wc=lw;
		}
		
		if (wc>MAXW) cerr<<"ERRROR"<<endl;
		for(int i=0;i<wc;i++) { 
			if (where[i][0]<0) { r--; continue; }
			for(int j=i+1;j<wc;j++) { 
				if (EQUAL2(
					(where[i][0]-where[j][0])*(where[i][0]-where[j][0])+
					(where[i][1]-where[j][1])*(where[i][1]-where[j][1])
					,0)) { 
					where[j][0]=-1;
				} 
			}
		}
		wc=0;
		
		fout<<"Case #"<<c+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

