#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > a(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(m);
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}

		vector<int> x(n), y(m);
		for (int i = 0; i < n; ++i) {
			x[i] = a[i][0];
			for (int j = 1; j < m; ++j) {
				x[i] = max(x[i], a[i][j]);
			}
		}
		for (int j = 0; j < m; ++j) {
			y[j] = a[0][j];
			for (int i = 1; i < n; ++i) {
				y[j] = max(y[j], a[i][j]);
			}
		}

		bool ok = true;
		for (int i = 0; i < n && ok; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] != min(x[i], y[j])) {
					ok = false;
					break;
				}
			}
		}

		cout << "Case #" << test << ": " << (ok ? "YES" : "NO") << endl;
	}
}
