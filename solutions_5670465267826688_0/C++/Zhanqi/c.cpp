#include <iostream>
#define QI 2
#define QJ 3
#define QK 4
using namespace std;


int qrule[5][5];
int L,X,T;
char l[140005];

void init() {
    qrule[ 1][ 1] =   1;
    qrule[ 1][QI] =  QI;
    qrule[ 1][QJ] =  QJ;
    qrule[ 1][QK] =  QK;

    qrule[QI][ 1] =  QI;
    qrule[QI][QI] =  -1;
    qrule[QI][QJ] =  QK;
    qrule[QI][QK] = -QJ;

    qrule[QJ][ 1] =  QJ;
    qrule[QJ][QI] = -QK;
    qrule[QJ][QJ] =  -1;
    qrule[QJ][QK] =  QI;

    qrule[QK][ 1] =  QK;
    qrule[QK][QI] =  QJ;
    qrule[QK][QJ] = -QI;
    qrule[QK][QK] =  -1;
}

void printNo(int t) {
	cout<<"Case #"<<t<<": NO"<<endl;
}

void printYes(int t) {
	cout<<"Case #"<<t<<": YES"<<endl;
}

int main() {
	init();
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>L>>X;
		for (int i=0; i<L; i++) cin>>l[i];
		if (X>14) {
			for (int i=14; i>=0; i--) {
				if ((X-i)%4==0) {X=i;break;}
			}
		}
		for (int i=1; i<X; i++)
			for (int j=0; j<L; j++)
				l[i*L+j]=l[j];
		L=X*L;
		//find first i
		//for (int i=0; i<L; i++) cout<<l[i];
		//	cout<<endl;
		int product=1;int endi=-1;
		for (int i=0; i<L; i++) {
			int index=int(l[i]-'i')+2;
			//cout<<l[i]<<endl;
			//cout<<"product="<<product<<"*"<<index<<endl;
			if (product<0) {
				product=-qrule[-product][index];
			} else {
				product=qrule[product][index];
			}
			if (product==2) {
				endi=i; break;
			}
		}
		if (endi==-1) {
			printNo(t);continue;
		}
		//cout<<endi<<endl;
		product=1;int endj=-1;
		for (int i=endi+1; i<L; i++) {
			int index=int(l[i]-'i')+2;
			if (product<0) {
				product=-qrule[-product][index];
			} else {
				product=qrule[product][index];
			}
			if (product==3) {
				endj=i; break;
			}
		}
		if (endj==-1) {
			printNo(t);continue;
		}
		//cout<<endj<<endl;
		product=1;
		for (int i=endj+1; i<L; i++) {
			int index=int(l[i]-'i')+2;
			if (product<0) {
				product=-qrule[-product][index];
			} else {
				product=qrule[product][index];
			}
		}
		if (product==4) {
			printYes(t);
		} else {
			printNo(t);
		}
	}
	return 0;
}







