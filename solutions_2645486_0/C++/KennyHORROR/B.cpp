#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int dp[12][12];
int v[12];

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		printf("Case #%d: ", I + 1);
		int e, r, n;
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		memset(dp, 0, sizeof dp);
		dp[0][e] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= e; ++j) {
				if (!dp[i][j]) {
					continue;
				}
				for (int k = 0; k <= j; ++k) {
					dp[i + 1][min(e, j - k + r)] = max(dp[i + 1][min(e, j - k + r)], dp[i][j] + k * v[i]);
				}
			}
		}
		printf("%d\n", dp[n][min(e, r)] - 1);
	}
	return 0;
}