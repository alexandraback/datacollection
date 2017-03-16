#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
typedef LL typec;

#define CY  2000
#define MAXN 6
int dp[CY][MAXN], ar[CY]; 
int N, E, R;

int main(void) {
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("m2.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; ++T) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 0; i < N; ++i) scanf("%d", &ar[i]);
		int tot = (1 << N) - 1;
		memset(dp, 0, sizeof(dp));
		for (int k = 0; k <= tot; ++k) {
			for (int i = 0; i < N; ++i) {
				if (!((1 << i) & k)) {
					for (int j = 0; j <= E; ++j) {
						for (int L = 0; L <= j; ++L) {
							int e = min(j - L + R, E);
							dp[k ^ (1 << i)][e] = max(dp[k ^ (1 << i)][e], dp[k][j] + ar[i] * L);
						}
					}
				}
			}
		}
		int mx = 0;
		for (int i = 0; i <= E; ++i) {
			mx = max(mx, dp[tot][i]);
		}
		printf("Case #%d: %d\n", T, mx);
	}
	return 0;
}

/*

3
5 2 1
2


*/
