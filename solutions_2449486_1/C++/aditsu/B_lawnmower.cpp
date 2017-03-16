#include <iostream>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n, m;
		cin >> n >> m;
		int a[n][m];
		int r[110] = {};
		int c[110] = {};
		set<int> v;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				int x;
				cin >> x;
				a[j][k] = x;
				r[j] += x;
				c[k] += x;
				v.insert(x);
			}
		}
		int ok = 1;
		while (v.size() > 1) {
			int x1 = *v.begin();
			int x2 = *++v.begin();
			for (int j = 0; j < n; ++j) {
				if (ok) for (int k = 0; k < m; ++k) {
					if (a[j][k] == x1 && r[j] != m * x1 && c[k] != n * x1) {
						ok = 0;
						break;
					}
				}
			}
			if (!ok) {
				break;
			}
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (a[j][k] == x1) {
						a[j][k] = x2;
						r[j] += x2 - x1;
						c[k] += x2 - x1;
					}
				}
			}
			v.erase(x1);
		}
		cout << "Case #" << i << ": " << (ok ? "YES" : "NO") << endl;
	}
}
