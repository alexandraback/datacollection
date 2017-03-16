#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <cassert>
#include <climits>
#include <memory.h>
#include <bitset>

using namespace std;

long long n, m, tt, st[61];
int a[51][51];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	st[0] = 1;
	for (int i = 1; i < 61; i++) {
		st[i] = st[i - 1] * 2;
	}
	cin >> tt;
	for (int i = 0; i < tt; i++) {
		cin >> n >> m;
		if (m > st[n - 2]) {
			cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
			continue;
		}
		m--;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				a[i][j] = 0;
			}
		}
		long long x = m;
		vector<int> v;
		for (int i = 0; i < n - 2; i++) {
			v.push_back(x % 2);
			x /= 2;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j > i) {
					a[i][j] = 1;
				}
			}
		}
		if (m == st[n - 2]) {
			cout << "Case #" << i + 1 << ": POSSIBLE" << endl;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << a[i][j];
				}
				cout << endl;
			}
			continue;
		}
		for (int i = 0; i < v.size(); i++) {
			if (!v[i]) {
				a[i + 2][n] = 0;
			}
		}
		cout << "Case #" << i + 1 << ": POSSIBLE" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}