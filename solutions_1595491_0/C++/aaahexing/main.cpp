#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, s, p;
int t[110], tb[40][2], dp[110][110];

void gaoTB() {
	memset(tb, -1, sizeof(tb));
	for (int i = 0; i < 35; ++i) {
		for (int a = 0; a <= i; ++a) {
			for (int b = 0; b <= i; ++b) {
				if (a + b <= i) {
					int c = i - a - b;
					int difab = abs(a - b);
					int difbc = abs(b - c);
					int difca = abs(c - a);
					if (difab <= 2 && difbc <= 2 && difca <= 2) {
						int sur = (difab == 2 || difbc == 2 || difca == 2);
						int maxi = max(a, max(b, c));
						tb[i][sur] = max(tb[i][sur], maxi);
					}
				}
			}
		}
	}
	//for (int i = 0; i <= 30; ++i) {
	//	printf("sur[%d] : %d, %d\n", i, tb[i][0], tb[i][1]);
	//}
}

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	gaoTB();
	int cas;
	scanf("%d%*c", &cas);
	for (int c = 1; c <= cas; ++c) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &t[i]);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= i && j <= s; ++j) {
				int cur_t = t[i];
				if (j > 0) {
					if (tb[cur_t][1] != -1) {
						//printf("[%d, %d] of [%d, %d], %d~%d\n", i, j, i - 1, j - 1, tb[cur_t][1], p);
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (tb[cur_t][1] >= p));
					}
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + (tb[cur_t][0] >= p));
			}
		}
		//for (int i = 1; i <= n; ++i) {
		//	for (int j = 0; j <= i && j <= s; ++j) {
		//		printf("%d ", dp[i][j]);
		//	}
		//	puts("");
		//}
		printf("Case #%d: %d\n", c, dp[n][s]);
	}

	return 0;
}