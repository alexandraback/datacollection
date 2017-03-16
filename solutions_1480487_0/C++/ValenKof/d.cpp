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
	vector<int> s(n);
	int x = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		x += s[i];
	}
	for (int i = 0; i < n; ++i) {
		double l = 0.0, r = 1.0;
		while (r - l > 1e-9) {
			double m = (l + r) / 2;
			double cur = s[i] + x * m;
			double need = 0.0;
			for (int j = 0; j < n; ++j) {
				need += max(0.0, (cur - s[j]) / x);
			}
			if (need <= 1.0 + 1e-9) l = m;
			else r = m;
		}
		cout << fixed << setprecision(6) << l * 100 << ' ';
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
	return 0;
}