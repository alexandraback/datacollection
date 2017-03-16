#include <bits/stdc++.h>
using namespace std;

typedef vector<string> VS;
VS matrix, temp;

bool check(int n, int m, int c) {
	matrix.resize(n);
	for (int i = 0; i < n; ++i) matrix[i] = string(m, '*');
	int r = n * m - c;
	bool ok = 0;
	if (r == 0) return 0;
	if (r == 1) {
		matrix[0][0] = '.';
		ok = 1;
	} else if (min(n, m) == 1) {
		for (int i = 0; r && i < n; ++i) {
			for (int j = 0; r && j < m; ++j) {
				matrix[i][j] = '.';
				--r;
			}
		}
		ok = 1;
	} else {
		for (int x = 2, y, z; !ok && x <= n; ++x) {
			y = r / x;
			z = r % x;
			if (y <= 1 || y + (z != 0) > m) continue;
			if (z == 1) {
				if (x <= 2 || y <= 2) continue;
				for (int i = 0; i < x; ++i) {
					for (int j = 0; j <= y; ++j) {
						matrix[i][j] = '.';
					}
				}
				for (int i = 1; i < x - z; ++i) matrix[x - i][y] = '*';
				matrix[x - 1][y - 1] = '*';
				ok = 1;
			} else {
				for (int i = 0; i < x; ++i) {
					for (int j = 0; j <= y; ++j) {
						matrix[i][j] = '.';
					}
				}
				for (int i = 1; i <= x - z; ++i) matrix[x - i][y] = '*';
				ok = 1;
			}
			cerr << x << '-' << y << ' ' << z << endl;
		}
		for (int y = 2, x, z; !ok && y <= m; ++y) {
			x = r / y;
			z = r % y;
			if (x <= 1 || x + (z != 0) > n) continue;
			if (z == 1) {
				if (x <= 2 || y <= 2) continue;
				for (int i = 0; i <= x; ++i) {
					for (int j = 0; j < y; ++j) {
						matrix[i][j] = '.';
					}
				}
				for (int i = 1; i < y - z; ++i) matrix[x][y - i] = '*';
				matrix[x - 1][y - 1] = '*';
				ok = 1;
			} else {
				for (int i = 0; i <= x; ++i) {
					for (int j = 0; j < y; ++j) {
						matrix[i][j] = '.';
					}
				}
				for (int i = 1; i <= y - z; ++i) matrix[x - 1][y - i] = '*';
				ok = 1;
			}
			cerr << x << '~' << y << ' ' << z << endl;
		}
	}
	matrix[0][0] = 'c';
	if (ok) for (int i = 0; i < n; ++i) cout << matrix[i] << endl;
	return ok;
}

int run() {
	int _, n, m, c;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas) {
		cin >> n >> m >> c;
		cout << "Case #" << cas << ":" << endl;
		if (!check(n, m, c)) cout << "Impossible" << endl;
	}
	return 0;
}

int main() {
	//freopen("in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout << setiosflags(ios::fixed) << setprecision(10);
	return run();
}
