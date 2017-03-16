#include <iostream>
#include <cstdio>

using namespace std;

int dp[200][200];
int n, S, p;
int score[200];

bool canDo(int sc, int p) {
	for (int i = p; i <= 10; ++i) {
		for (int j = i-1; j <= i; ++j) {
			for (int k = j; k <= i; ++k) {
				if (j >= 0 && k >= 0) {
					if (k + j + i == sc) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool canDoSurp(int sc, int p) {
	for (int i = p; i <= 10; ++i) {
		for (int j = i-2; j <= i-2; ++j) {
			for (int k = j; k <= i; ++k) {
				if (k >= 0 && j >= 0) {
					if (k + j + i == sc) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void solve() {
	scanf("%d%d%d", &n, &S, &p);
	for (int i = 0; i < n; ++i) {
		scanf("%d", score + i);
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= S; ++j) {
			if (dp[i][j] != -1) {
				if (canDo(score[i], p)) {
					dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
				}
				if (canDoSurp(score[i], p) && j < S) {
					dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
				}
				if (canDo(score[i], 0)) {
					dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				}
				if (canDoSurp(score[i], 0) && j < S) {
					dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
				}
			}
		}
 	}	
	printf("%d\n", dp[n][S]);	
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;

	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}