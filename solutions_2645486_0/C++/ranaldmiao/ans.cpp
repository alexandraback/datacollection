#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int tc, e, r, n, v[15], dp[15][10];
int brute (int x, int m) {
	m = min(m, e);
	if (dp[x][m] != -1) return dp[x][m];
	if (m < 0) return -1000000000;
	if (x == n) return 0;
	dp[x][m] = -1000000;
	for (int i = 0; i <= m; ++i) {
		dp[x][m] = max(dp[x][m], v[x]*i + brute(x+1, m-i+r));
	}
	return dp[x][m];

}
int main () {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		memset(v, 0, sizeof(v));
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
		printf("Case #%d: %d\n", t, brute(0, e));
	}
}