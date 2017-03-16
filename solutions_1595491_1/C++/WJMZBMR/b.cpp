/*
 * b.cpp
 *
 *  Created on: 2012-4-14
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 100 + 10;

int n, s, p;
int t[MAX_N];

int dp[MAX_N][MAX_N]; //i,ns

void work(int id) {
	cin >> n >> s >> p;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;

	for (int i = 0; i < n; ++i) {
		bool can[2][2] = { };
		for (int a = 0; a < 20; ++a) {
			for (int b = a; b <= a + 2; ++b) {
				for (int c = b; c <= a + 2; ++c) {
					if (a + b + c == t[i]) {
						can[c - a == 2][c >= p] = true;
					}
				}
			}
		}

		for (int j = 0; j <= s; ++j) {
			for (int a = 0; a < 2; ++a) {
				for (int b = 0; b < 2; ++b)
					if (can[a][b]) {
						dp[i + 1][j + a] = max(dp[i + 1][j + a], dp[i][j] + b);
					}
			}
		}

	}

	printf("Case #%d: %d\n", id, dp[n][s]);
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		work(i);
	}
	return 0;
}
