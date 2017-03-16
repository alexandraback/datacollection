#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int getnew(int od, int bit, int tbit) {
	if (bit == tbit) return od;
	if (bit > tbit) return 0;
	else return 2;
}

long long solve() {
	long long A, B, K;
	scanf("%lld%lld%lld", &A, &B, &K);
	long long dp[31][3][3][3];
	memset(dp, 0, sizeof(dp));
	dp[0][1][1][1] = 1;
	for (int i = 0; i < 30; i++) {
		for (int oa = 0; oa < 3; oa++) {
			for (int ob = 0; ob < 3; ob++) {
				for (int ok = 0; ok < 3; ok++) {
					for (int a = 0; a < 2; a++) {
						for (int b = 0; b < 2; b++) {
							int k = a&b;
							int na = getnew(oa, (A >> i) & 1, a);
							int nb = getnew(ob, (B >> i) & 1, b);
							int nk = getnew(ok, (K >> i) & 1, k);
							dp[i + 1][na][nb][nk] += dp[i][oa][ob][ok];
						}
					}
				}
			}
		}
	}
	return dp[30][0][0][0];
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d: %lld\n", c, solve());
	}
}