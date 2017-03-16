
#include <iostream>

#include <algorithm>

using namespace std;

typedef unsigned long long ull;

void solve() {
	int B;
	ull M;

	cin >> B >> M;

	ull max = 1L << (B-2);

	if (M > max) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	cout << "POSSIBLE" << endl;

	bool almost = (M == max);
	bool e[B][B];
	for (int i = 0; i < B; i++)
	for (int j = 0; j < B; j++) {
		e[i][j] = (i < j) && (almost || j != B-1);
	}

	if (M < max) {
		for (int b = 2; b < B; b++) {
			if (M & (1 << (b-2))) {
				e[b-1][B-1] = true;
			}
		}
	}

	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B; j++) {
			cout << (e[i][j] ? '1' : '0');
		}
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}

