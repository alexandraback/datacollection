#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int itc;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(2*n-1, vector<int>(n));
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> b(n, vector<int>());
	vector<bool> inb(a.size(), false);
	for (int k = 0; k < n; k++) {
		int minaik = 2501;
		for (int i = 0; i < (int)a.size(); i++) if (!inb[i]) {
			minaik = min(minaik, a[i][k]);
		}
		for (int i = 0; i < (int)a.size(); i++) {
			if (a[i][k] == minaik) {
				b[k].push_back(i);
				inb[i] = true;
				// printf("%d ", i);
			}
		}
		// puts("");
	}
	vector<int> c(2*n-1, 0);
	int k0 = -1;
	for (int k = 0; k < n; k++) {
		if ((int)b[k].size() == 1) {
			k0 = k;
		}
		for (int i: b[k]) {
			for (int j = 0; j < n; j++) {
				c[k+j] ^= a[i][j];
			}
		}
	}
	// printf("%d\n", k0);
	for (int j = 0; j < n; j++) {
		printf(" %d", c[k0+j]);
	}
	puts("");
}

int main() {
	cin.sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	for (itc = 1; itc <= ntc; itc++) {
		printf("Case #%d:", itc);
		solve();
	}
}
