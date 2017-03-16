
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 101;
int test_case, n, s, p, t[maxn], fg[maxn][5], f[maxn][maxn];

int bscore(int a, int b, int c) {
	return max(a, max(b, c));
}

int bsup(int a, int b, int c) {
	return max(a, max(b, c)) - min(a, min(b, c));
}

int main() {
	scanf("%d", &test_case);
	for (int tt = 1; tt <= test_case; ++tt) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &t[i]);
		}
		memset(fg, 0, sizeof(fg));
		for (int i = 1; i <= n; ++i) {
			for (int a = 0; a <= 10; ++a) {
				for (int b = a; b <= min(10, a + 2); ++b) {
					int c = t[i] - a - b;
					if (c >= 0 && c <= 10 && bsup(a, b, c) <= 2) {
						if (bscore(a, b, c) >= p) {
							if (bsup(a, b, c) == 2) {
								fg[i][1] = true; 
							} else {
								fg[i][2] = true; 
							}
						} else {
							if (bsup(a, b, c) == 2) {
								fg[i][3] = true;
							} else {
								fg[i][4] = true; 
							}
						}
					}
				}
			}
		}
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= s; ++j) {
				if (fg[i][1] && j > 0) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);	
				if (fg[i][2]) f[i][j] = max(f[i][j], f[i - 1][j] + 1);
				if (fg[i][3] && j > 0) f[i][j] = max(f[i][j], f[i - 1][j - 1]);
				if (fg[i][4]) f[i][j] = max(f[i][j], f[i - 1][j]);
			}
		}
		printf("Case #%d: %d\n", tt, f[n][s]);
	}
	return 0;
}
