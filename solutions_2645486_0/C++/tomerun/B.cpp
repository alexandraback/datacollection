#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

int E,R,N,V[10001];
ll dp[11][10];

ll solve() {
	scanf("%d %d %d", &E, &R, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", V+i);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][E] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= E; ++j) {
			if (dp[i][j] == -1) continue;
			for (int k = 0; k <= j; ++k) {
				int next = min(E, j - k + R);
				dp[i+1][next] = max(dp[i+1][next], dp[i][j] + V[i] * k);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= E; ++i) {
		ans = max(ans, dp[N][i]);
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		printf("Case #%d: %lld\n", tc, solve());
	}
}
