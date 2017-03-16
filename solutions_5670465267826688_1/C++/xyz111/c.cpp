#include <cstdio>
#include <string.h>
using namespace std;

int a[4][4], T, l;
char S[110000];
long long x;

struct Matrix {
	bool s[24][24];
	void cl() {
		for (int i = 0; i < 24; i++)
			for (int j = 0; j < 24; j++)
				s[i][j] = (i == j);
	}
} mat[4];

Matrix operator * (Matrix A, Matrix B) {
	Matrix C;
	memset(C.s, false, sizeof C.s);
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 24; j++)
			for (int p = 0; p < 24; p++)
				C.s[i][j] |= (A.s[i][p] & B.s[p][j]);
	return C;
}

Matrix Pow(Matrix A, long long x) {
	Matrix B;
	B.cl();
	for (long long i = 1; i <= x; i *= 2, A = A * A)
		if (i & x) B = B * A;
	return B;
}

int go(int x, int y) {
	if (x < 4 && y < 4)
		return a[x][y];
	if (x >= 4 && y >= 4)
		return a[x - 4][y - 4];
	int t = a[x % 4][y % 4];
	if (t < 4) return t + 4;
	else return t - 4;
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C1.out", "w", stdout);
	a[0][0] = 0; a[0][1] = 1; a[0][2] = 2; a[0][3] = 3;
	a[1][0] = 1; a[1][1] = 4; a[1][2] = 3; a[1][3] = 6;
	a[2][0] = 2; a[2][1] = 7; a[2][2] = 4; a[2][3] = 1;
	a[3][0] = 3; a[3][1] = 2; a[3][2] = 5; a[3][3] = 4;
	for (int j = 1; j <= 3; j++) {
		memset(mat[j].s, 0, sizeof mat[j].s);
		for (int i = 0; i < 24; i++) {
			int t = i % 8;
			int p = go(t, j);
			mat[j].s[i][i / 8 * 8 + p] = true;
			if (1 <= p && p < 3 && p == i / 8 + 1) {
				mat[j].s[i][i / 8 * 8 + 8] = true;
			}
		}
	}
	scanf("%d", &T);
	
	for (int k = 1; k <= T; k++) {
		scanf("%d%lld", &l, &x);
		scanf("%s", S);
		Matrix M;
		M.cl();
		for (int i = 0; i < l; i++) {
			if (S[i] == 'i') M = M * mat[1];
			else if (S[i] == 'j') M = M * mat[2];
			else M = M * mat[3];
		}
		M = Pow(M, x);
		if (M.s[0][19]) printf("Case #%d: YES\n", k);
		else printf("Case #%d: NO\n", k);
	}
}
