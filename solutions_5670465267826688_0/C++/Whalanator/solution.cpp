#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int mtable[8][8] = {
	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0},
	{4,5,6,7,0,1,2,3},
	{5,0,7,2,1,4,3,6},
	{6,3,0,5,2,7,4,1},
	{7,6,1,0,3,2,5,4}
};

int T,cas,n1,n2;
long long c,L,X;
string s1;

int main() {
	cin >> T;
	for (cas=1;cas<=T;cas++) {
		cin >> L >> X >> s1;
		n1=0;n2=1;
		for (c=0;c<150000 && c<L*X && n2<3; c++) {
			n1=mtable[n1][s1[c%L]-'i'+1];
			if (n1==n2) {
				n2++;
				n1=0;
			}
		}
		cout << "Case #" << cas << ": ";
		if (n2!=3) {cout << "NO" << endl; continue;}
		for (;c%L;c++) n1=mtable[n1][s1[c%L]-'i'+1];
		n2=0;
		for (int cc=0;cc<L;cc++) n2=mtable[n2][s1[cc]-'i'+1];
		for (int cc=0;cc<((L*X-c)/L)%4;cc++) n1=mtable[n1][n2];
		if (n1==3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
