#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <io.h>
#include <stdint.h>
#include <queue>
using namespace std;

typedef int32_t I32;
typedef int64_t I64;
typedef uint64_t UI64;

int dp[20][20];
int v[100];
int main() {
	int T, TC = 1;;
	int R, n, E;
	
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &E, &R, &n);
		for (int i=0; i<n; i++) scanf("%d", &v[i]);
		memset(dp, -1, sizeof(dp));
		dp[0][E] = 0;
		for (int i=0; i<n; i++) for (int j=0; j<=E; j++)
			if (dp[i][j] != -1) {
				for (int k=0; k<=j; k++)
					dp[i+1][min(j-k+R, E)] = max(dp[i+1][min(j-k+R, E)], dp[i][j] + k*v[i]);
			}
		//for (int i=0; i<=n; i++) for (int j=0; j<=E; j++) if (dp[i][j] != -1) printf("%d %d %d\n",i,j,dp[i][j]);
		int ans = 0;
		for (int j=0; j<=E; j++)
			ans = max(ans, dp[n][j]);

		printf("Case #%d: %d\n", TC++, ans);
	}
}