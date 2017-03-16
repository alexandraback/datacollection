#pragma comment(linker, "/stack:256000000")

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

long long dp[20][20];

long long solver(int e, int r, int n, const vector <int> &v) {
	memset(dp, 0, sizeof(dp));
	REP(i, n) {
		for (int j = 0; j <= e; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i + 1][min(e, j - k + r)] = max(dp[i + 1][min(e, j - k + r)], dp[i][j] + (long long)v[i] * k);
			}
		}
	}
	long long res = *max_element(dp[n], dp[n] + e + 1);
	return res;
}

//long long greedy(int e, int r, int n, const vector <int> &v) {
//}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long start = clock();
#endif
	int tst;
	cin >> tst;
	REP(_, tst) {
		int e, r, n;
		cin >> e >> r >> n;
		vector <int> v(n);
		REP(i, n) cin >> v[i];
		long long res = solver(e, r, n, v);
		cout << "Case #" << (_ + 1) << ": " << res << "\n";
	}
#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf\n\n", (clock() - start) / 1000.);
#endif
	return 0;
}