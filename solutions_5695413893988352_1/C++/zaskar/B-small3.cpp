#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int make(const string &s, const string &s2, int f) {
	int n=0;
	for(size_t i=0;i<s.size();i++)
//		n = n*10 + (s[i]=='?'? (s2[i]=='?'?f:(s2[i]-'0')) :(s[i]-'0'));
		n = n*10 + (s[i]=='?'? f :(s[i]-'0'));
	return n;
}


void test2(string &C, string &J, string &rC, string &rJ, int &mind, int &minc, int &minj, int i, int cc,int cj, int fi, int fj) {
	C[i]='0'+cc;
	J[i]='0'+cj;
	int newc = make(C,J,fi);
	int newj = make(J,C,fj);
	int d = abs(newc-newj);
	if (mind==-1 || d<mind || (d==mind && (newc<minc || (newc==minc && newj<minj)))) {
		mind=d; minc=newc; minj=newj;
		rC=C; rJ=J;
	}
	
}

void test(string &C, string &J, string &rC, string &rJ, int &mind, int &minc, int &minj, int i, int cc,int cj) {
	for(int k=0;k<100;k++)
		test2(C,J,rC,rJ,mind,minc,minj,i,cc,cj,k/10,k%10);
}

int main(int argc, char *argv[]) {
//	string fname = "B-sample";
//	string fname = "B-small-attempt4";
		string fname = "B-large";
	ifstream fin(fname+".in");
	ofstream fout(fname+".out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		string C,J,rC,rJ;
		fin>>C>>J;
		cout<<C<<" "<<J<<endl;
		for(size_t i=0;i<C.size();i++) { 
			int mind=-1,minc,minj;
			if (C[i]=='?' && J[i]=='?') {
				for(int j=0;j<10;j++) {
					for(int k=0;k<10;k++) {
						test(C,J,rC,rJ,mind,minc,minj,i,j,k);
						test(C,J,rC,rJ,mind,minc,minj,i,j,k);
					}
				}
				C[i]=rC[i];
				J[i]=rJ[i];
			} else if (C[i]=='?') {
				int mind=-1,minc,minj;
				for(int k=0;k<10;k++) {
					test(C,J,rC,rJ,mind,minc,minj,i,k,J[i]-'0');
					test(C,J,rC,rJ,mind,minc,minj,i,k,J[i]-'0');
				}
				C[i]=rC[i];
			} else if (J[i]=='?') {
				int mind=-1,minc,minj;
				for(int k=0;k<10;k++) {
					test(C,J,rC,rJ,mind,minc,minj,i,C[i]-'0',k);
					test(C,J,rC,rJ,mind,minc,minj,i,C[i]-'0',k);
				}
				J[i]=rJ[i];
			}
			
		}
		cout<<rC<<" "<<rJ<<endl;
		fout<<"Case #"<<I+1<<": "<<rC<<" "<<rJ<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

