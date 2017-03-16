#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXN 15
#define MAXE 8

int v[MAXN];
int dp[MAXN][MAXE];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		int E, R, N;
		scanf("%d%d%d", &E, &R, &N);
		for(int i = 1; i <= N; ++i) scanf("%d", v + i);
		memset(dp, -1, sizeof(dp));
		dp[0][E] = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j <= E; ++j) if(dp[i][j] != -1) {
				for(int k = 0; k <= j; ++k) {
					int rem = min(E, R + j - k);
					dp[i + 1][rem] = max(dp[i + 1][rem], dp[i][j] + k * v[i + 1]);
				}
			}
		int res = 0;
		for(int i = 0; i <= E; ++i)
			res = max(res, dp[N][i]);
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
