#include<stdio.h>
#include<algorithm>
#include<map>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define N 110
int dp[N][N], d[N];
int main() {
	//freopen("","r",stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf(" %d", &T);
	int cas = 1;
	while (T--) {
		int a, n;
		scanf(" %d %d", &a, &n);
		for (int i = 1; i <= n; i++) {
			scanf(" %d", &d[i]);
		}
		sort(d + 1, d + n + 1);
		memset(dp, -1, sizeof(dp));
		dp[0][0] = a;

		for (int e = 1; e <= n; e++) {
			dp[0][e] = max(dp[0][e], dp[0][e - 1] * 2 - 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[i - 1][j] == -1)
				continue;
				if (d[i] < dp[i - 1][j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + d[i]);
				}
				dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]);
			}
			for (int e = 1; e <= n; e++) {
				dp[i][e] = max(dp[i][e], dp[i][e - 1] * 2 - 1);
			}
		}
		int ans = n;
		for (int i = 0; i <= n; i++) {
			if (dp[n][i] != -1) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", cas++, ans);
		fflush(stdout);
	}
	return 0;
}
/*
 4
 2 2
 2 1
 2 4
 2 1 1 6
 10 4
 25 20 9 100
 1 4
 1 1 1 1
 */
