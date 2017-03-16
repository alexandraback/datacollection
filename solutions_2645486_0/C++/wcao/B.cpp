#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <cstdlib>

using namespace std;

int T;
int E, R, N;

long long dp[99][9];

inline void mmax(long long &x, long long y) {x = max(x, y);}

int main() {
	scanf("%d", &T);
	for(int t = 1 ; t <= T ; t++) {
		scanf("%d %d %d", &E, &R, &N);
		memset(dp, 0, sizeof(dp));
		for(int a , i = 0 ; i < N ; i++) {
			scanf("%d", &a);
			for(int j = 0 ; j <= E ; j++) {
				for(int used = 0 ; used <= j ; used++) {
					mmax(dp[i + 1][min(j - used + R, E)], dp[i][j] + used * a);
				}
			}
		}
		long long ans = 0;
		for(int j = 0 ; j <= E ; j++)
			ans = max(ans, dp[N][j]);
		printf("Case #%d: %lld\n", t, ans);
	}
}
