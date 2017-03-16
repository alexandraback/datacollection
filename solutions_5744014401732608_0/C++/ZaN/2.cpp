#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int b;
		long long m;
		cin >> b >> m;

		int n = 0;
		long long v = 1;
		while (v < m) {
			++n;
			v <<= 1;
		}

		if (b < n + 2) {
			cout << "Case #" << test << ": IMPOSSIBLE" << endl;
			continue;
		}

		int g[50][50];
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < b; ++j) {
				g[i][j] = 0;
			}
		}

		if (v == m) {
			g[0][b - 1] = 1;
			--m;
		}
		for (int i = b - 2; i >= b - n - 1; --i) {
			for (int j = i + 1; j < b; ++j) {
				g[i][j] = 1;
			}
			if ((m & 1) != 0) {
				g[0][i] = 1;
			}
			m >>= 1;
		}

		cout << "Case #" << test << ": POSSIBLE" << endl;
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < b; ++j) {
				cout << g[i][j];
			}
			cout << endl;
		}
	}
}
