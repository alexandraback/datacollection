#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int B = 51;

int g[B][B];

int main() {
#ifdef _DEBUG
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		int b;
		ll m;
		cin >> b >> m;
		ll max = ll(1) << (b - 2);
		if (max < m) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			memset(g, 0, B*B*sizeof(int));
			for (int i = 1; i < b - 1; i++) {
				for (int j = i + 1; j < b; j++) {
					g[i][j] = 1;
				}
			}

			int k = b - 2;
			m--;
			g[0][b - 1] = 1;
			while (m > 0) {
				if (m % 2 == 1) {
					g[0][k] = 1;
				}
				m = m / 2;
				k--;
			}

			cout << "POSSIBLE" << endl;
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++) {
					cout << g[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}