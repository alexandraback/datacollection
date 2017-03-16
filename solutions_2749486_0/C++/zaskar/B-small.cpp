#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int d(int a, int b) {
	int x=a-b;
	if (x<0) return -x; else return x;
}

#define minimo(a) (a<=dxM && a<=dxm && a<=dym && a<=dyM && a<=ax && a<=ay)
#define minimox(a) (a<=dxM && a<=dxm && a<=ax)
#define minimoy(a) (a<=dyM && a<=dym && a<=ay)

int main(int argc, char *argv[]) {
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int x=0,y=0,X,Y;
		fin>>X>>Y;
		char xm='W',xM='E',ym='S',yM='N';
		if (X<0) { X=-X; swap(xM,xm); }
		if (Y<0) { Y=-Y; swap(yM,ym); }
		fout<<"Case #"<<I+1<<": ";
		int n=1;
		while (x!=X || y!=Y) {
			int ax=d(x,X), ay=d(y,Y);
			int dxM=d(x+n,X), dxm=d(x-n,X);
			int dyM=d(y+n,Y), dym=d(y-n,Y);
			if (x==X) { ax=dxM=dxm=abs(ay)+abs(dym)+abs(dyM)+1; }
			if (y==Y) { ay=dyM=dym=abs(ax)+abs(dxm)+abs(dxM)+1; }
			if (minimo(dxM)) {
				x+=n; fout<<xM;
			} else if (minimo(dxm)) {
				x-=n; fout<<xm;
			} else if (minimo(dyM)) {
				y+=n; fout<<yM;
			} else if (minimo(dym)) {
				y-=n; fout<<ym;
			} else if (minimo(ax)) {
				if (X>x) {
					fout<<xm; x-=n;
				} else {
					fout<<xM; x+=n;
				}
			} else if (minimo(ay)) {
				if (Y>y) {
					fout<<ym; y-=n;
				} else {
					fout<<yM; y+=n;
				}
			}
			n++;
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

