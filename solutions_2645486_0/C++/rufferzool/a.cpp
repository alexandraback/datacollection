#include <cstdio>
#include <algorithm>

using namespace std;

int v[100], dp[100][10];

int main() {
	int T;
	scanf(" %d", &T);
	for(int z = 1; z <= T; z ++) {
		int e, r, n;
		scanf(" %d %d %d", &e, &r, &n);
		for(int i = 0; i < n; i ++)
			scanf(" %d", v + i);
		for(int i = 0; i < n; i ++) {
			for(int j = 0; j <= e; j ++) {
				if(i == 0)
					dp[i][j] = (e - j) * v[i];
				else {
					int val = 0;
					for(int k = 0; k <= e; k ++) {
						if(min(e, k + r) >= j)
							val = max(val, dp[i - 1][k] + (min(e, k + r) - j) * v[i]);
					}
					dp[i][j] = val;
				}
				//printf("DP[%d][%d] = %d", i, j, dp[i][j]);
			}
		}
		printf("Case #%d: %d\n", z, dp[n - 1][0]);
	}
	return 0;
}
