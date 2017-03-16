#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define ll long long
#define ld long double
#define mp make_pair
#define TASKNAME "monument"


const int inf = 2 * 1e9;
const int mod = 1e9 + 7;
const ll infll = (ll)1e18;
const ld eps = 1e-9;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

using namespace std;

int ways(vector<vector<int>> g) {
	int n = g.size();
	vector<int> dp(n, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j])
				dp[j] += dp[i];
		}
	}
	return dp[n - 1];
}

void solve() {
	int b, m;
	cin >> b >> m;
	int p = 15;
	for (int mask = 0; mask < (1 << p); mask++) {
		int c = 0;
		vector<vector<int>> g(b, vector<int>(b, 0));
		for (int i = 0; i < b; i++) {
			for (int j = i + 1; j < b; j++) {
				if (i == j)
					continue;
				if (mask & (1 << c++))
					g[i][j] = 1;
			}
		}
		int t = ways(g);
		if (t > m * 10)
			break;
		if (t == m) {
			cout << "POSSIBLE\n";
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++) {
					cout << g[i][j];
				}
				if (i != b - 1)
					cout << endl;
			}
			return;
		}
	}
	cout << "IMPOSSIBLE";
}

int main() {
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#else
	//assert(freopen(TASKNAME".in", "r", stdin));
	//assert(freopen(TASKNAME".out", "w", stdout));
#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cerr << "Test #" << t + 1 << " in progress\n";
		cout << "Case #" << t + 1 << ": ";
		solve();
		cout << endl;
		cerr << "Test #" << t + 1 << " done\n";
	}

#ifdef __DEBUG__
	fprintf(stderr, "\nTime: %Lf\n", ((clock() - start) / (ld)CLOCKS_PER_SEC));
#endif
	return 0;
}