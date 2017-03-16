#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0);

	int tests;
	cin >> tests;

	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		vector <char> ca(n), cb(n);
		bool T = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			if (a[i] == 0 || b[i] == 0) T = true;
		}

		int cur = 0, ans = 0;

		if (T)
		for (;;) {
			bool t = false;
			for (int i = 0; i < n; i++) {
				if (!ca[i] && !cb[i] && cur >= b[i]) {
					cur += 2;
					ans++;
					ca[i] = cb[i] = t = true;
				}
			}

			if (t) continue;

			for (int i = 0; i < n; i++) {
				if (ca[i] && !cb[i] && cur >= b[i]) {
					cur ++;
					ans++;
					ca[i] = cb[i] = t = true;
					break;
				}
			}

			if (t) continue;

			int mx = -1, idx = mx;

			for (int i = 0; i < n; i++) {
				if (!ca[i] && !cb[i] && a[i] <= cur && b[i] > mx) {
					mx = b[i];
					idx = i;
				}
			}

			if (idx == -1) break;
			t = true;
			ca[idx] = true;
			ans++;
			cur++;
		}

		for (int i = 0; i < n; i++) {
			if (!cb[i] || !ca[i]) T = false;
		}

		cout << "Case #" << test + 1 << ": ";
		if (T) cout << ans; else cout << "Too Bad";
		cout << endl;
	}
		
}