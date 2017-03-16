#include <cstdio>
#include <cstring>

int T, E, R, N;
int v[11], dp[11][6];

inline int min(int a, int b) {
	return a<b ? a : b;
}

inline int max(int a, int b) {
	return a>b ? a : b;
}

int main() {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		scanf("%d%d%d", &E, &R, &N);
		memset(dp, 0, sizeof(dp));
		for(int p=1; p<=N; p++) {
			scanf("%d", &v[p]);
			for(int i=0; i<=E; i++)
				for(int j=0; j<=i; j++)
					dp[p][ min(i-j+R, E) ] = max( dp[p][min(i-j+R,E)], dp[p-1][i]+j*v[p] );
			//for(int i=0; i<=E; i++)
			//	printf("%d/%d: %d\n", p, i, dp[p][i]);
		}
		int ans = 0;
		for(int i=0; i<=E; i++)
			ans = max(dp[N][i], ans);
		printf("Case #%d: %d\n", tc, ans);
	}
}
