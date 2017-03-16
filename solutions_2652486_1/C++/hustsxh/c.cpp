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
	//cout << "count: " << x << " " << k << endl;
	while(x % k == 0) {
		x /= k;
		cnt += 1;
	}
	return cnt;
}
int solve() {
	int r, n, m, k;
	cin >> r >> n >> m >> k;

	for (int p = 0; p < r; ++p) {
		int m5 = 0, m7 = 0, m2 = 0, m3 = 0, m32 = 0, cnt = 0, x[20], m23 = 0;
		for (int i = 0; i < k; ++i) {
			cin >> x[i];
			m2 = max(m2, count(x[i], 2));
			m32 = max(m32, count(x[i], 3) - count(x[i], 2));
			m23 = max(m23, count(x[i], 2) - count(x[i], 3));
			m3 = max(m3, count(x[i], 3));
			m5 = max(m5, count(x[i], 5));
			m7 = max(m7, count(x[i], 7));
		}
		//printf("%d %d %d %d\n", m2, m3, m5, m7);
		for (int i = 0; i < m32; ++i) {
			cout << '3';
		}
		for(int i = 0; i < m5; ++i) {
			cout << '5';
		}
		for (int i = 0; i < m3 - m32; ++i) {
			cout << '6';
		}
		for (int i = 0; i < m7; ++i) {
			cout << '7';
		}
		cnt = n - m3 - m5 - m7;
		while(m23 >= 3 && cnt) {
			cout << '8';
			m23 -= 3;
			-- cnt;
		}
		if(m23 == 2 && cnt) {
			cout << '4';
			-- cnt;
		}
		for(int i = 0; i < cnt; ++i) {
			cout << '6';
		}
		cout << endl;
	}
	return 0;
}

int main() {
	int T;
	freopen("C-small-2-attempt1.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":\n";
		solve();
	}
}
