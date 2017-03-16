#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int count(int x, int k) {
	int cnt = 0;
	while(x % k == 0) {
		x /= k;
		cnt += 1;
	}
	return cnt;
}
int solve() {
	int r, n, m, k;
	cin >> r >> n >> m >> k;
	for (int i = 0; i < r; ++i) {
		int m3 = 0, m5 = 0, x, m2[7] = {0};
		for (int j = 0; j < k; ++j) {
			cin >> x;
			m2[count(x, 2)] = 1;
			m3 = max(m3, count(x, 3));
			m5 = max(m5, count(x, 5));
		}
		for (int j = 0; j < m3; ++j) {
			cout << '3';
		}
		for (int j = 0; j < m5; ++j) {
			cout << '5';
		}
		if (m3 + m5 == 0) {
			if (m2[6]) {
				cout << "444";
			} else {
				cout << "244";
			}
		} else if (m3 + m5 == 1) {
			if (m2[4]) {
				cout << "44";
			} else {
				cout << "24";
			}
		} else if (m3 + m5 == 2) {
			if (m2[2]) {
				cout << "4";
			} else {
				cout << "2";
			}
		}
		cout << endl;
	}
	return 0;
}

int main() {
	int T;
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":\n";
		solve();
	}
}
