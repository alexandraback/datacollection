#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int k = (1 << n);
	vector<int> w(n);
	vector<int> dp(k, 0);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				dp[i] += w[j];
			}
		}
	}

	for (int i = 1; i < k; ++i) {
		for (int j = i&(i-1); j != 0; j = (j-1)&i) {
			int mask1 = i ^ j;
			int mask2 = j;
			int s1 = dp[mask1];
			int s2 = dp[mask2];
			if (s1 == s2) {
				for (int i = 0; i < n; ++i) {
					if (mask1 & (1 << i)) {
						cout << w[i] << ' ';
					}
				}
				cout << endl;
				for (int i = 0; i < n; ++i) {
					if (mask2 & (1 << i)) {
						cout << w[i] << ' ';
					}
				}

				return;
			}
		}
	}
	cout << "Impossible";
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": " << endl;
		solve();
		cout << endl;
	}
	return 0;
}