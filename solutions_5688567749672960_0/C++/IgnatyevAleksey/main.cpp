#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define mp make_pair
#define sqr(x) ((x) * (x))
#define all(a) a.begin(), a.end()

typedef long long int64;

const int INF = (int) 2e9;
const int64 INF64 = (int64) 1e18;
const double EPS = 1e-9;

const int N = (int) 1e6 + 100;
int dp[N];

int rev(int x) {
	int res = 0;
	do {
		res *= 10;
		res += x % 10;
		x /= 10;
	} while (x > 0);

	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tests;
	scanf("%d", &tests);

	for (int t = 0; t < tests; t++) {
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			dp[i] = INF;
		}

		dp[1] = 1;

		for (int i = 1; i < n; i++) {
			dp[i + 1] = min(dp[i + 1], dp[i] + 1);
			int r = rev(i);
			if (r > i) {
				dp[r] = min(dp[r], dp[i] + 1);
			}
		}

		printf("case #%d: %d\n", t + 1, dp[n]);
	}

	return 0;
}