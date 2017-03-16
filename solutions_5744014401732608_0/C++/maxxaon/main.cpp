#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <deque>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <numeric>
#include <assert.h>
#include <iomanip>
#include <unordered_map>

using namespace std;

long long f[51][51], n, m, dp[51];

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				f[i][j] = dp[j] = 0;
		dp[0] = 1;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 0; j < i; j++)
				dp[i] += dp[j];
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n - 1; j++)
				f[i][j] = 1;
		}
		for (int i = n - 2; i >= 0; i--) {
			if (dp[i] <= m) {
				m -= dp[i];
				f[i][n - 1] = 1;
			}
		}
		if (m == 0) {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					cout << f[i][j];
				cout << endl;
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}