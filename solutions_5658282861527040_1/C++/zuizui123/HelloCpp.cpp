#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define fi "B-large.in"
#define fo "out.txt"
const int MAXN = 32;
const int INF = 1000000000;

int T, A, B, K;
long memo[MAXN][2][2][2][2][2][2];

long dp(int, int, int, int, int, int, int);
int bitOf(int, int);

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> A >> B >> K;
		--A;
		--B;
		--K;
		for (int i = 0; i < MAXN; ++i) {
			for (int bitK = 0; bitK < 2; ++bitK) {
				for (int smallK = 0; smallK < 2; ++smallK) {
					for (int bitA = 0; bitA < 2; ++bitA) {
						for (int smallA = 0; smallA < 2; ++smallA) {
							for (int bitB = 0; bitB < 2; ++bitB) {
								for (int smallB = 0; smallB < 2; ++smallB) {
									memo[i][bitK][smallK][bitA][smallA][bitB][smallB] = -1;
								}
							}
						}
					}
				}
			}
		}
		long res = dp(31, 0, 0, 0, 0, 0, 0);
		cout << res << endl;
	}
}

long dp(int i, int bitK, int smallK, int bitA, int smallA, int bitB, int smallB) {
	if (memo[i][bitK][smallK][bitA][smallA][bitB][smallB] > -1) {
		return memo[i][bitK][smallK][bitA][smallA][bitB][smallB];
	}
	if (i == 0) {
		memo[i][bitK][smallK][bitA][smallA][bitB][smallB] = 1;
		return 1;
	}
	int limit;
	if (smallK) {
		limit = 1;
	} else {
		limit = bitOf(K, i - 1);
	}
	int limitA, limitB;
	if (smallA) {
		limitA = 1;
	} else {
		limitA = bitOf(A, i - 1);
	}
	if (smallB) {
		limitB = 1;
	} else {
		limitB = bitOf(B, i - 1);
	}
	memo[i][bitK][smallK][bitA][smallA][bitB][smallB] = 0;
	for (int d = 0; d <= limit; ++d) {
		if (d == 1) {
			if (limitA == 1 && limitB == 1) {
				memo[i][bitK][smallK][bitA][smallA][bitB][smallB] += dp(i - 1, d, smallK | (d < bitOf(K, i - 1)), 1, smallA | (1 < bitOf(A, i - 1)), 1, smallB | (1 < bitOf(B, i - 1)));
			}
		} else {
			for (int dA = 0; dA <= limitA; ++dA) {
				for (int dB = 0; dB <= limitB; ++dB) {
					if ((dA & dB) == 0) {
						memo[i][bitK][smallK][bitA][smallA][bitB][smallB] += dp(i - 1, d, smallK | (d < bitOf(K, i - 1)), dA, smallA | (dA < bitOf(A, i - 1)), dB, smallB | (dB < bitOf(B, i - 1)));
					}
				}
			}
		}
	}
	return memo[i][bitK][smallK][bitA][smallA][bitB][smallB];
}

int bitOf(int x, int t) {
	return ((x >> t) & 1);
}
