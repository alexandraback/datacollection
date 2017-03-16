#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[55][55];

bool gao(int r, int c, int m) { // r >= c
	memset(a, 0, sizeof(a));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			a[i][j] = '*';
	int n = r * c - m;
	if (n == 1) {
		;
	} else if (c == 1) {
		for (int i = 1; i < n; ++i) a[i][0] = '.';
	} else if (c == 2) {
		if (n % 2 || n == 2) return false;
		for (int i = 0; i < n / 2; ++i)
			a[i][0] = a[i][1] = '.';
	} else if (n == 2 || n == 3 || n == 5 || n == 7) {
		return false;
	} else if (n >= 2 * c + 2) {
		for (int k = 0, i = 0; i < r; ++i) {
			for (int j = 0; j < c && k < n; ++j, ++k) {
				a[i][j] = '.';
			}
		}
		if (n % c == 1) {
			a[n / c][1] = '.';
			a[n / c - 1][c - 1] = '*';
		}
	} else if (n & 1) {
		for (int i = 0; i < (n - 3) / 2; ++i) {
			a[0][i] = a[1][i] = '.';
		}
		a[2][0] = a[2][1] = a[2][2] = '.';
	} else {
		for (int i = 0; i < n / 2; ++i) {
			a[0][i] = a[1][i] = '.';
		}
	}
	a[0][0] = 'c';
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		int r, c, m, inv = 0;
		scanf("%d%d%d", &r, &c, &m);
		if (r < c) { swap(r, c); inv = 1; }
		printf("Case #%d:\n", cas);
		if (!gao(r, c, m)) puts("Impossible");
		else {
			if (inv) {
				for (int j = 0; j < c; ++j) {
					for (int i = 0; i < r; ++i)
						putchar(a[i][j]);
					puts("");
				}
			} else {
				for (int i = 0; i < r; ++i) puts(a[i]);
			}
		}
	}
}