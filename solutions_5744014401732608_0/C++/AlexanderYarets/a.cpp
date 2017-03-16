#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1000000009;
const int maxn = 1000000009;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		ll n, m; cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(n));
		vector<int> z{ 1, 2, 3, 4, 5 };
		a[0][n - 1] = 1;
		m--;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n - 1; ++j) {
				//cout << z[i] << " " << z[j] << endl;
				if (a[i][j] == 0) {
					a[i][j] = 1;
					
					if (a[0][i] == 0) {
						a[0][i] = 1;
					}
					if (a[j][n - 1] == 0) {
						a[j][n - 1] = 1;
					}
				}	
				m--;
				if (m == 0) break;
			}
			if (m == 0) break;
		}

		if (m) {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
			continue;
		} else {
			cout << "Case #" << t << ": POSSIBLE" << endl;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << a[i][j];
				}
				cout << endl;
			}
		}

	}

	return 0;
}