#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 32;
const int MAXM = 20;

int n, s, p;
bool valid[MAXN][MAXM], surprise[MAXN][MAXM], nonsurprise[MAXN][MAXM];

bool isValid(int a, int b, int c) {
	return c - a <= 2;
}

bool isSurprise(int a, int b, int c) {
	return c - a == 2;
}

void init() {
	for (int a = 0; a <= 10; a++) {
		for (int b = a; b <= 10; b++) {
			for (int c = b; c <= 10; c++) {
				if (!isValid(a, b, c)) continue;
				valid[a + b + c][c] = true;
//printf("a = %d b = %d c = %d (%d)\n", a, b, c, a + b + c);
				if (isSurprise(a, b, c)) {
					surprise[a + b + c][c] = true;
				} else {
					nonsurprise[a + b + c][c] = true;
				}
			}
		}
	}
	for (int score = 0; score <= 30; score++) {
		for (int mmax = 9; mmax >= 0; mmax--) {
			surprise[score][mmax] |= surprise[score][mmax + 1];
			nonsurprise[score][mmax] |= nonsurprise[score][mmax + 1];
		}
		for (int mmax = 1; mmax <= 10; mmax++) {
			valid[score][mmax] |= valid[score][mmax - 1];
		}
	}
}

const int MAXS = 128;

int dp[MAXS][MAXS];

int main() {
	init();
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 0; taskIdx < taskNumber; taskIdx++) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= s; j++) {
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		for (int o = 0; o < n; o++) {
			int score;
			scanf("%d", &score);
//printf("surprise[%d][%d] = %d nonsurprise[%d][%d] = %d valid[%d][%d] = %d\n", score, p, surprise[score][p], score, p, nonsurprise[score][p], score, p - 1, valid[score][p - 1]);
			for (int i = 0; i <= s; i++) {
				if (dp[o][i] == -1) continue;
				if (surprise[score][p]) {
					dp[o + 1][i + 1] = max(dp[o + 1][i + 1], dp[o][i] + 1);
				}
				if (surprise[score][0]) {
					dp[o + 1][i + 1] = max(dp[o + 1][i + 1], dp[o][i]);
				}
				if (nonsurprise[score][p]) {
					dp[o + 1][i] = max(dp[o + 1][i], dp[o][i] + 1);
				}
				if (nonsurprise[score][0]) {
					dp[o + 1][i] = max(dp[o + 1][i], dp[o][i]);
				}
				if (p && valid[score][p - 1]) {
					dp[o + 1][i] = max(dp[o + 1][i], dp[o][i]);
				}
			}
		}
		printf("Case #%d: %d\n", taskIdx + 1, dp[n][s]);
	}
	return 0;
}
