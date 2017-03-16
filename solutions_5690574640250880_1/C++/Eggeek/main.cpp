#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 100
char g[maxn][maxn];
int FLAG;

void printans(int r,int c,int a,int b,int i,int j) {
	// printf("r:%d c:%d a:%d b:%d i:%d j:%d\n", r,c,a,b,i,j);
	for (int R=0 ; R<a ; R++ ) {
		for (int C=0 ; C<b ; C++ ) {
			g[R][C] = '.';
		}
	}

	// for (int x=0 ; x<r ; x++ ) printf("%s\n", g[x]);

	for (int R=0 ; R<i ; R++ ) g[R][b] = '.';
	for (int C=0 ; C<j ; C++ ) g[a][C] = '.';
	g[0][0] = 'c';
	if (!FLAG) {
		for (int R=0 ; R<r ; R++ ) printf("%s\n",g[R]);	
	} else {
		// printf("r:%d c:%d\n", r,c);
		for (int C=0 ; C<c ; C++ ) {
			for (int R=0 ; R<r ; R++ )
				printf("%c",g[R][C]);
			printf("\n");
		}
	}
}

int work(int r,int c,int m) {
	int rest = r*c-m;
	// printf("rest:%d\n", rest);
	for (int a=2 ; a<=r ; a++ ) {
		for (int b=2 ; b<=c ; b++ ) {
			int dif = rest-a*b;
			// printf("dif:%d\n", dif);
			// if (dif<=3) continue;
			for (int i=0 ; i<=dif && i<=a; i++ ) {
				int j = dif-i;
				if (j>b) continue;
				if (a==r && j) continue;
				if (b==c && i) continue;
				if (i && i<2) continue;
				if (j && j<2) continue;
				printans(r,c,a,b,i,j);
				return true;
			}
		}
	}
	return false;
}

int main() {
	int cas;
	freopen("test.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	scanf("%d",&cas);
	for (int t=1 ; t<=cas ; t++ ) {
		printf("Case #%d:\n",t);
		int r,c,m;
		int flg = 0;
		FLAG = 0;
		scanf("%d%d%d",&r,&c,&m);
		int rest = r*c-m;
		if (r>c) {
			swap(r,c);
			FLAG = 1;
		}
		memset(g,0,sizeof(g));
		for (int i=0 ; i<r ; i++ )
			for (int j=0 ; j<c ; j++ ) g[i][j]='*';
		if (r==1) {
			printans(r,c,1,rest,0,0);
			flg = true;
		} else {
			int rest = r*c-m;
			if (rest==1) {
				flg = true;
				printans(r,c,1,1,0,0);
			} else {
				flg = work(r,c,m);
			}
		}
		if (!flg) printf("Impossible\n");
	}
	return 0;
}