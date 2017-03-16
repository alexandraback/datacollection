#include <bits/stdc++.h>

using namespace std;

int T;
int r,c,mine,kosong;
char mat[100][100];

#define R(i,a,b) for (int i=a; i<=b; i++)

void print (int tc) {
	// printf ("Case #%d:\n",tc);
	R(i,1,r) R(j,1,c) {
		cout << mat[i][j];
		if (j == c) puts("");
	}
}

int main () {
	cin >> T;
	for (int tc=1; tc<=T; tc++) {
		scanf ("%d %d %d",&r,&c,&mine);
		printf ("Case #%d:\n",tc);
		kosong = r*c - mine;
		
		if (mine <= max(r-2,0)*max(c-2,0)) {
			memset(mat,'.',sizeof(mat));
			R(i,1,max(r-2,0)) R(j,1,max(c-2,0)) 
				if (mine > 0)
					mat[i][j] = '*', mine--;
			mat[r][c] = 'c';
			print (tc);
			continue;
		}
		
		if (kosong == 1) {
			memset(mat,'*',sizeof(mat));
			mat[1][1] = 'c';
			print(tc);
			continue;
		}
		
		
		if (r == 1) {
			memset(mat,'.',sizeof(mat));
			R(i,1,mine) mat[1][i] = '*';
			mat[1][c] = 'c';
			print(tc);
			continue;
		}
		
		if (c == 1) {
			memset(mat,'.',sizeof(mat));
			R(i,1,mine) mat[i][1] = '*';
			mat[r][1] = 'c';
			print(tc);
			continue;
		}
		
		if (r == 2) {
			memset(mat,'.',sizeof(mat));
			if (mine % 2 == 1 or kosong < 4) { puts("Impossible"); continue; }
			R(i,1,mine/2) mat[1][i] = mat[2][i] = '*';
			mat[r][c] = 'c';
			print(tc);
			continue;
		}
		
		if (c == 2) {
			memset(mat,'.',sizeof(mat));
			if (mine % 2 == 1 or kosong < 4) { puts("Impossible"); continue; }
			R(i,1,mine/2) mat[i][1] = mat[i][2] = '*';
			mat[r][c] = 'c';
			print(tc);
			continue;
		}
		
		if (kosong == 2 or kosong == 3 or kosong == 5 or kosong == 7) {
			puts("Impossible");
			continue;
		}
		
		memset(mat,'*',sizeof(mat));
		if (kosong % 2 == 1) {
			R(i,1,3) R(j,1,3) mat[i][j] = '.';
			mat[1][1] = 'c';
			kosong -= 9;
			for (int i=4; i<=r; i++) if (kosong > 0) {
				mat[i][1] = mat[i][2] = '.';
				kosong -= 2;
			}
			for (int i=4; i<=c; i++) if (kosong > 0) {
				mat[1][i] = mat[2][i] = '.';
				kosong -= 2;
			}
			print(tc);
			continue;
		}
			
			R(i,1,2) R(j,1,2) mat[i][j] = '.';
			mat[1][1] = 'c';
			kosong -= 4;
			for (int i=3; i<=r; i++) if (kosong > 0) {
				mat[i][1] = mat[i][2] = '.';
				kosong -= 2;
			}
			for (int i=3; i<=c; i++) if (kosong > 0) {
				mat[1][i] = mat[2][i] = '.';
				kosong -= 2;
			}
			print(tc);
	}
}