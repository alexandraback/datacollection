#include <cstdio>

using namespace std;

const int MAXN = 110;
const int MAXE = 110;

int ar[MAXN];
int T;
int E, R, N;

int dp[MAXN][MAXE];

int get(int n, int e) {
	if (e > E) e = E;
	if (n == N) return 0;
	int &ret = dp[n][e];
	if (ret) return ret - 1;

	for(int i = 0; i <= e; ++i) {
		int val = get(n + 1, i + R) + (e - i) * ar[n];
		if (val > ret) ret = val;
	}

	return ret++;
}

int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d %d %d", &E, &R, &N);
		for(int i = 0; i < N; ++i) {
			scanf("%d", ar + i);
		}

		for(int i = 0; i < N; ++i) {
			for(int j = 0; j <= E; ++j) {
				dp[i][j] = 0;
			}
		}

		int ans = get(0, E);
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
