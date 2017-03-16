#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;
int tests, e, r, n, v[11], dp[11][11];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 1; i <= n; ++i) scanf("%d", v + i);
		memset(dp, 0x80, sizeof(dp));
		dp[0][e] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= e; ++j) {
				for (int k = 0; k <= j; ++k) {
					int &value = dp[i + 1][min(e, j - k + r)];
					value = max(value, dp[i][j] + k * v[i + 1]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= e; ++j) {
				ans = max(ans, dp[i][j]);
			}
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}