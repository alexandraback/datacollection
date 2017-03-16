#include <cstdio>

#define N 128

inline int max(int a, int b) {
	return a < b ? b : a;
}

int T, n, s, p, t, dp[N][N], cnt;
bool d[N][2];

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d%d%d", &n, &s, &p);
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &t);
			if (t == 0) { cnt += (0 >= p); --i; --n; continue; }
			if (t == 1) { cnt += (1 >= p); --i; --n; continue; }
			if (t == 29) { cnt += (10 >= p); --i; --n; continue; }
			if (t == 30) { cnt += (10 >= p); --i; --n; continue; }
			if (t%3 == 0) {
				d[i][0] = (t/3     >= p); d[i][1] = (t/3 + 1 >= p);
			} else if (t%3 == 1) {
				d[i][0] = (t/3 + 1 >= p); d[i][1] = (t/3 + 1 >= p);
			} else {
				d[i][0] = (t/3 + 1 >= p); d[i][1] = (t/3 + 2 >= p);
			}
		}
		for (int j = 0; j <= s; ++j) dp[0][j] = 0;
		for (int i = 0; i < n; ++i) {
			dp[i + 1][0] = dp[i][0] + d[i][0];
			for (int j = 1; j <= s; ++j)
				dp[i + 1][j] = max(dp[i][j] + d[i][0], dp[i][j - 1] + d[i][1]);
		}
		printf("%d\n", cnt + dp[n][s]);
	}
}
