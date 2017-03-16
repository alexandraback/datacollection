#include <cstdio>
#include <cstdlib>
#include <cstring>

const int multa[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

char st[10005];
int a[10005];
bool f[10005][3][9];

int mul(int x, int y) {
	int sx = x > 4 ? -1 : 1;
	int sy = y > 4 ? -1 : 1;
	x = x > 4 ? 9 - x : x;
	y = y > 4 ? 9 - y : y;
	int m = multa[abs(x)][abs(y)] * sx * sy;
	return m < 0 ? 9 + m : m;
}

int main() {
	int testNum;
	scanf("%d", &testNum);
	for (int test = 1; test <= testNum; ++test) {
		int L, X;
		scanf("%d%d", &L, &X);
		scanf("%s", st);
		int N = 0;
		for (int i = 0; i < X; ++i)
			for (int j = 0; j < L; ++j) {
				if (st[j] == '1') a[N++] = 1;
				if (st[j] == 'i') a[N++] = 2;
				if (st[j] == 'j') a[N++] = 3;
				if (st[j] == 'k') a[N++] = 4;
			}
		memset(f, 0, sizeof(f));
		f[0][0][1] = true;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j <= 2; ++j)
				for (int k = 1; k <= 8; ++k)
					if (f[i][j][k]) {
						int x = mul(k, a[i]);
						f[i + 1][j][x] = true;
						if (j == 0 && x == 2) f[i + 1][1][1] = true;
						if (j == 1 && x == 3) f[i + 1][2][1] = true;
					}
		printf("Case #%d: %s\n", test, f[N][2][4] ? "YES" : "NO");
	}
	return 0;
}