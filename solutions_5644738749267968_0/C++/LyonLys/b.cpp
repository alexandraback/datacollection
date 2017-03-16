#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef double DB;
const int T = 1000000;
const DB EPS = 1e-10;

int run() {
	int _, n;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas) {
		cin >> n;
		VI a(n), b(n);
		double temp;
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			a[i] = (temp + EPS) * T;
		}
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			b[i] = (temp + EPS) * T;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		//for (int i = 0; i < n; ++i) cout << i << ' ' << a[i] << ' ' << b[i] << endl;
		int i, j, ans1, ans2;
		ans1 = ans2 = 0;
		i = j = 0;
		while (i < n && j < n) {
			while (j < n && a[i] > b[j]) ++j;
			if (j < n) ++ans2;
			++i, ++j;
		}
		i = j = 0;
		while (i < n && j < n) {
			while (i < n && a[i] < b[j]) ++i;
			if (i < n) ++ans1;
			++i, ++j;
		}
		cout << "Case #" << cas << ": " << ans1 << ' ' << n - ans2 << endl;
	}
	return 0;
}

int main() {
	//freopen("in", "r", stdin);
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	ios::sync_with_stdio(0);
	return run();
}
