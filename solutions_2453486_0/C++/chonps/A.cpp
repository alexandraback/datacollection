#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small-attempt0.out");
char c[4][4];
int main(){
	int i,j,k,m,n,Ti,ti,O,X,T;
	fin >> Ti;
	for (ti=1;ti<=Ti;++ti){
		for (i=0;i<4;++i)
			fin >> c[i];
		k=0;
		for (i=0;i<4;++i)
			for (j=0;j<4;++j)
				k+=c[i][j]=='.';
		m=0;
		for (i=0;i<4 && !m;++i){
			for (O=X=T=j=0;j<4;++j){
				if (c[i][j]=='O') ++O;
				else if (c[i][j]=='T') ++T;
				else if (c[i][j]=='X') ++X;
			}
			if (!O || !X){
				if (O && O+T==4 && T<2) m=1;
				if (X && X+T==4 && T<2) m=2;
			}
		}
		for (j=0;j<4 && !m;++j){
			for (O=X=T=i=0;i<4;++i){
				if (c[i][j]=='O') ++O;
				else if (c[i][j]=='T') ++T;
				else if (c[i][j]=='X') ++X;
			}
			if (!O || !X){
				if (O && O+T==4 && T<2) m=1;
				if (X && X+T==4 && T<2) m=2;
			}
		}
		for (O=X=T=i=0;i<4 && !m;++i){
			if (c[i][i]=='O') ++O;
			else if (c[i][i]=='T') ++T;
			else if (c[i][i]=='X') ++X;
		}
		if (!O || !X){
			if (O && O+T==4 && T<2) m=1;
			if (X && X+T==4 && T<2) m=2;
		}
		for (O=X=T=i=0;i<4 && !m;++i){
			if (c[i][3-i]=='O') ++O;
			else if (c[i][3-i]=='T') ++T;
			else if (c[i][3-i]=='X') ++X;
		}
		if (!O || !X){
			if (O && O+T==4 && T<2) m=1;
			if (X && X+T==4 && T<2) m=2;
		}
		fout << "Case #" << ti << ": ";
		if (m){
			fout << (m==1?"O":"X") << " won" << endl;
			continue;
		}
		else fout << (k?"Game has not completed":"Draw") << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
