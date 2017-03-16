#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

void drawline(int x, int l, bool flag = false) {
	for (int i=0; i<x; i++) printf("*");
	for (int i=0; i<l-x-1; i++) printf(".");
	if (x == l) printf("\n");
	else if (flag) printf("c\n");
	else printf(".\n");
}
int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int T;
	int R, C, M;
	scanf("%d", &T);
	for (int T0=1; T0 <= T; T0++) {
		printf("Case #%d:\n", T0);
		scanf("%d%d%d", &R, &C, &M);
		
		if (R == 1) {
			drawline(M, C, true);
			continue;
		}
		if (C == 1) {
			printf("c\n");
			for (int i=0; i<R-M-1; i++) printf(".\n");
			for (int i=0; i<M; i++) printf("*\n");
			continue;
		}
		if (M == R*C-1) {
			for (int i=0; i<R-1; i++) drawline(C, C);
			drawline(C-1, C, true);
			continue;
		}
		if (R*C-M < 9 && R*C-M != 4 && R*C-M != 6 && R*C-M !=8) {
			printf("Impossible\n");
			continue;
		}
		if ((C==2 || R==2) && (M&1)) {
			printf("Impossible\n");
			continue;
		}
		if (R==2) {
			int a = M/2;
			drawline(a, C);
			drawline(a, C, true);
			continue;
		}
		int len = M/C;
		if (len < R-3) {
			for (int i=0; i<len; i++) drawline(C, C);
			if (M%C != C-1) {
				drawline(M%C, C); drawline(0, C);
			} else {
				drawline(M%C-1, C); drawline(1, C);
			}
			for (int i=0; i<R-len-3; i++) drawline(0, C);
			drawline(0, C, true);
			continue;
		}
		
		len = R-3;
		int rest = M - len*C;
		
		for (int i=0; i<len; i++) drawline(C, C);
		int col = rest/3;
		drawline(col + rest%3, C);
		drawline(col, C);
		drawline(col, C, true);
	}
	return 0;
}

