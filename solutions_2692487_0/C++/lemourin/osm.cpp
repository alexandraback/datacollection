#include <cstdio>
#include <algorithm>
const int INF = 1e9+5;
const int MAXV = 1e6+5;
const int MAXN = 105;

int dp[MAXV+1][2], T[MAXN];

void set(int& a, int b) {
	a = std::min(a, b);
}

int main() {
	int t;
	scanf("%d", &t);

	for (int test=1; test<=t; test++) {
		int v, n;
		scanf("%d%d", &v, &n);

		for (int i=0; i<n; i++)
			scanf("%d", &T[i]);

		std::sort(T, T+n);
		for (int i=0; i<MAXV; i++)
			dp[i][0] = dp[i][1] = INF;
		
		dp[v][0] = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<MAXV; j++) {
				if (j > T[i] && j+T[i] < MAXV)
					set(dp[j+T[i]][1], dp[j][0]);
				else if (j > 1) {
					int p = j, c = 0;
					while (p <= T[i])
						p = p*2-1, c++;
					if (p+T[i] < MAXV)
						set(dp[p+T[i]][1], dp[j][0]+c);
				}
				
				set(dp[j][1], dp[j][0]+1);

			}

			for (int j=0; j<MAXV; j++) {
				//printf("dp[%d][%d] = %d\n", j, i+1, dp[j][1]);
				dp[j][0] = dp[j][1];
				dp[j][1] = INF;
			}
		}

		printf("Case #%d: %d\n", test, *std::min_element(dp[0], dp[0]+MAXV));
	}
}
