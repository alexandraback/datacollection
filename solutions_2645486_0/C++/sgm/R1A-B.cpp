#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int T;
int E, R, N;
int v[10001];
int dp[2][10001];

int main(void) {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d%d%d", &E, &R, &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &v[i]);
		}
		memset(dp[0], 0, sizeof(dp[0]));
		for(int i = 1; i <= N; i++) {
			int current = i % 2;
			int previous = 1 - current;
			for(int e = 0; e <= E; e++) {
				int max_gain = -1;
				for(int f = 0; f <= E; f++) {
					int spent = min(f + R, E) - e;
					if(spent < 0 || dp[previous][f] < 0) continue;
					int gain = dp[previous][f] + v[i] * spent;
					max_gain = max(max_gain, gain);
				}
				dp[current][e] = max_gain;
			}
		}
		printf("Case #%d: %d\n", t, dp[N % 2][0]);
	}
	return 0;
}
