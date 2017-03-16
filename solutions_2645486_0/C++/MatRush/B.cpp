#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 12;
int E, R, N, v[MAXN];
int dp[MAXN][MAXN];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; T++) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &v[i]);
		}
		memset(dp, -63, sizeof(dp));
		dp[0][E] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= E; j++) {
				for (int k = 0; k <= j; k++) {
					int &now = dp[i + 1][min(j - k + R, E)];
					now = max(now, dp[i][j] + k * v[i + 1]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= E; i++) {
			ans = max(ans, dp[N][i]);
		}
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}

