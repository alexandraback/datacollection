#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int dp[11][6];

int main() 
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	int ncas;
	scanf("%d", &ncas);
	int e, r, n, v;
	for (int cas = 1; cas <= ncas; ++cas) {
		scanf("%d%d%d", &e, &r, &n);
		memset(dp, -1, sizeof(dp));
		dp[0][e] = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v);
			for (int j = 0; j <= e; ++j) {
				if (dp[i][j] < 0) continue;
				for (int k = 0; k <= j; ++k) {
					int l = j - k + r;
					l = (l > e) ? e : l;
					dp[i + 1][l] = (dp[i + 1][l] < (dp[i][j] + k * v)) ? 
								(dp[i][j] + k * v) : dp[i + 1][l];
				}
			}
		}
		int ans = -1;
		for (int i = (r > e) ? e : r ; i <= e; ++i) {
			ans = dp[n][i] > ans ? dp[n][i] : ans;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	//system("pause");
	return 0;
}
