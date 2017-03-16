#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int T, R, C, M, T0;
int mat[55][55];

void Print() {
	int i, j;
	printf("Case #%d:\n", ++T0);
	for(i = 1; i <= R; ++i) {
		for(j = 1; j <= C; ++j) {
			if(mat[i][j] == 1)
				printf("*");
			if(mat[i][j] == 2)
				printf("c");
			if(mat[i][j] == 0)
				printf(".");
		}
		puts("");
	}
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	int i, j, k, l;
	scanf("%d", &T);
	for( ; T; --T) {
		memset(mat, 0, sizeof(mat));
		scanf("%d%d%d", &R, &C, &M);
		M = R * C - M;
		if(M == R * C) {
			mat[1][1] = 2;
			Print();
			continue;
		}
		if(R == 1 || C == 1) {
			M = R * C - M;
			for(i = R; i && M > 0; --i)
				for(j = C; j && M > 0; --j) {
					mat[i][j] = 1; --M;
				}
			mat[1][1] = 2;
			Print();
			continue;
		}
		int fl = 0;
		for(i = 2; i <= R && fl == 0; ++i)
			for(j = 2; j <= C && fl == 0; ++j)
				if(i * j == M) {
					for(k = 1; k <= R; ++k)
						for(l = 1; l <= C; ++l)
							mat[k][l] = 1;
					for(k = 1; k <= i; ++k)
						for(l = 1; l <= j; ++l)
							mat[k][l] = 0;
					fl = 1;
				}
		if(fl) {
			mat[1][1] = 2;
			Print();
			continue;
		}
		if(M == 2 || M == 3) {
			printf("Case #%d:\n", ++T0);
			puts("Impossible");
			continue;
		}
		if(M == 1) {
			for(i = 1; i <= R; ++i)
				for(j = 1; j <= C; ++j)
					mat[i][j] = 1;
			mat[1][1] = 2;
			Print();
			continue;
		}
		for(i = 2; i <= R && fl == 0; ++i)
			for(j = 2; j <= C && fl == 0; ++j) {
				if(i * j > M)
					continue;
				int tmp = M - i * j, res = 0, ca = 0, cb = 0;
				if(i != R) {
					res += j;
					ca = j;
				}
				if(j != C) {
					res += i;
					cb = i;
				}
				if(tmp > res) continue;
				if(tmp == 1) continue;
				if(tmp == 3 && i == 2 && j == 2) continue;
				fl = 1;
				for(k = 1; k <= i; ++k)
					for(l = 1; l <= j; ++l)
						mat[k][l] = 1;
				if(i != R && tmp <= j) {
					for(k = 1; k <= tmp; ++k)
						mat[i + 1][k] = 1;
					fl = 1; continue;
				}
				if(j != C && tmp <= i) {
					for(k = 1; k <= tmp; ++k)
						mat[k][j + 1] = 1;
					fl = 1; continue;
				}
				ca = j; cb = tmp - j;
				if(cb == 1) { --ca; ++cb; }
				for(k = 1; k <= ca; ++k) mat[i + 1][k] = 1;
				for(k = 1; k <= cb; ++k) mat[k][j + 1] = 1;
				fl = 1;
			}
		if(!fl) {
			printf("Case #%d:\n", ++T0);
			puts("Impossible");
			continue;
		}
		for(i = 1; i <= R; ++i)
			for(j = 1; j <= C; ++j)
				mat[i][j] ^= 1;
		mat[1][1] = 2;
		Print();
	}
	return 0;
}
