#include <stdio.h>

#define MAXN 15
#define MAXE 10

int dp[MAXN][MAXE];
int activities[MAXN];

int N, E, R, T;

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int c, i, j, k;

	scanf("%d", &T);

	for (c = 1; c <= T; c++){
		scanf("%d %d %d", &E, &R, &N);
		
		for (i = 0; i < N; i++)
			for (j = 0; j <= E; j++)
				dp[i][j] = 0;

		for (i = 0; i < N; i++)
			scanf("%d", &activities[i]);

		for (j = 0; j <= E; j++)
			dp[N-1][j] = activities[N-1] * j;

		for (i = N-2; i >= 0; i--)
			for (j = 0; j <= E; j++)
				for (k = 0; k <= j; k++)
					dp[i][j] = max(dp[i][j], dp[i+1][k+R] + activities[i] * (j-k));

		printf("Case #%d: %d\n", c, dp[0][E]);
	}

	return 0;
}
