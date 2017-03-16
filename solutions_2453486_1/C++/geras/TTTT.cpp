// Author: Kamil Niziński
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
char T[5][6];
inline bool W(int i,char c) {
	for(int j=0;j<4;j++) if(T[i][j]!=c&&T[i][j]!='T') return 0;
	return 1;
}
inline bool K(int j,char c) {
	for(int i=0;i<4;i++) if(T[i][j]!=c&&T[i][j]!='T') return 0;
	return 1;
}
inline bool RD(char c) {
	for(int i=0;i<4;i++) if(T[i][i]!=c&&T[i][i]!='T') return 0;
	return 1;
}

inline bool LD(char c) {
	for(int i=0;i<4;i++) if(T[i][3-i]!=c&&T[i][3-i]!='T') return 0;
	return 1;
}
void solve(int nr) {
	int i,j;
	for(i=0;i<4;i++) scanf("%s",T[i]);
	printf("Case #%d: ",nr);
	// sprawdzam O
	for(i=0;i<4;i++) if(W(i,'O')) {
		printf("O won\n");
		return;
	}
	for(j=0;j<4;j++) if(K(j,'O')) {
		printf("O won\n");
		return;
	}
	if(RD('O')||LD('O')) {
		printf("O won\n");
		return;
	}
	// a teraz X
	for(i=0;i<4;i++) if(W(i,'X')) {
		printf("X won\n");
		return;
	}
	for(j=0;j<4;j++) if(K(j,'X')) {
		printf("X won\n");
		return;
	}
	if(RD('X')||LD('X')) {
		printf("X won\n");
		return;
	}
	// nic nie ma, to sprawdzam, czy gra się skończyła
	for(i=0;i<4;i++) for(j=0;j<4;j++) if(T[i][j]=='.') {
		printf("Game has not completed\n");
		return;
	}
	printf("Draw\n");
}
int main() {
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++) solve(i);
	return 0;
}