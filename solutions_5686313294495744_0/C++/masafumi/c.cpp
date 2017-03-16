#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;

int solve(int n, vector<string> &v1, vector<string> &v2) {
	map<string, int> m1, m2;
	for (int i = 0; i < n; i++) {
		m1[v1[i]]++;
		m2[v2[i]]++;
	}

	int limit = 1 << n;
	vector<int> dp(limit + 1, 0);
	for (int bits = 0; bits < limit; bits++) {

		for (int i = 0; i < n; i++) {
			if (bits & (1 << i)) {
				continue;
			}

			bool fake1 = false;
			bool fake2 = false;

			for (int j = 0; j < n; j++) {
				if (j == i) {
					continue;
				}

				if (bits & (1 << j)) {
					if (v1[j] == v1[i]) {
						fake1 = true;
					}
					if (v2[j] == v2[i]) {
						fake2 = true;
					}
				}
			}
			if (fake1 && fake2) {
				int next = bits | (1 << i);
				dp[next] = max(dp[next], dp[bits] + 1);
			}
		}
	}

	return dp[limit - 1];
}

int main() {
	int t;
	string s;

	cin >> t;
	vector<int> ans(t);
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<string> v1(n), v2(n);
		for (int i = 0; i < n; i++) {
			cin >> v1[i] >> v2[i];
		}
		ans[i] = solve(n, v1, v2);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
