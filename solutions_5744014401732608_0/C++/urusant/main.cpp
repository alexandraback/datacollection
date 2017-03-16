#include <bits/stdc++.h>
using namespace std;

void solve() {
	int b;
	long long m;
	cin >> b >> m;
	if (m > (1LL << (b - 2))) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	vector <vector <bool> > ans(b, vector <bool> (b, 0));
	for (int i = 0; i < b - 1; ++i) {
		for (int j = i + 1; j < b - 1; ++j) {
			ans[i][j] = 1;
		}
	}
	if (m == (1LL << (b - 2))) {
		ans[0][b - 1] = 1;
		m--;
	}
	for (int i = 1; i < b - 1; ++i) {
		if ((m & (1 << (i - 1))) > 0) {
			ans[i][b - 1] = 1;
		}
	}
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	return;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
}