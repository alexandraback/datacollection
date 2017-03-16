#include <fstream> 
#include <iostream>
using namespace std;

int T,X,R,C,a,b;
bool vinco;
ifstream fin("input.txt");
ofstream fout("output.txt");

void f() {
	vinco = false;
	if (X>=7){ vinco = true; return; }
	if ((R*C)%X!=0){ vinco = true; return; }
	if (X>2 && R==2 && C==2){ vinco = true; return; }
	if (X>2 && C==1){ vinco = true; return; }
	if (X==4 && C==2){ vinco = true; return; }
	if (X==5 && C<3){ vinco = true; return; }
	if (X==5 && C==3 && R==5){ vinco = true; return; }
	if (X==6 && C<4){ vinco = true; return; }
	return;
	
}

int main() {
	fin>>T;
	for (int i =0; i<T; i++) {
		fin>>X>>a>>b;
		if (a>b) {
			R=a;
			C=b;
		} else {
			R=b;
			C=a;
		}
		f();
		if (vinco==true) fout<<"Case #"<<i+1<<": "<<"RICHARD"<<"\n";
		else fout<<"Case #"<<i+1<<": "<<"GABRIEL"<<"\n";
	}
	return 0;
}
