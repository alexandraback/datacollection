#include <iostream>
using namespace std;

void solve() {
	int R, C, M;
	cin >> R >> C >> M;
	if (R * C - M == 1) {
		cout << 'c';
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j)
				if (i || j)
					cout << '*';
			cout << endl;
		}
		return;
	}
	if (M == 0) {
		cout << 'c';
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j)
				if (i || j)
					cout << '.';
			cout << endl;
		}
		return;
	}
	if (R == 1 || C == 1) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j)
				if (M) {
					--M;
					cout << '*';
				} else if (i < R - 1 || j < C - 1) {
					cout << '.';
				} else {
					cout << 'c';
				}
			cout << endl;
		}
		return;
	}
	char x[R][C];
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			x[i][j] = '.';
	x[0][0] = 'c';
	if (R * C - M == 2 || R * C - M == 3 || R * C - M == 5 || R * C - M == 7) {
		cout << "Impossible" << endl;
		return;
	}
	for (int i = R - 1; i >= 2 && M; --i)
		for (int j = C - 1; j >= 2 && M; --j, --M)
			x[i][j] = '*';
	if (M % 2 == 0) {
		for (int i = R - 1; i >= 2 && M; --i, M -= 2)
			x[i][0] = x[i][1] = '*';
		for (int i = C - 1; i >= 2 && M; --i, M -= 2)
			x[0][i] = x[1][i] = '*';
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j)
				cout << x[i][j];
			cout << endl;
		}
		return;
	}
	if (R == 2 || C == 2) {
		cout << "Impossible" << endl;
		return;
	}
	++M;
	x[2][2] = '.';
	for (int i = R - 1; i >= 3 && M; --i, M -= 2)
		x[i][0] = x[i][1] = '*';
	for (int i = C - 1; i >= 3 && M; --i, M -= 2)
		x[0][i] = x[1][i] = '*';
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
			cout << x[i][j];
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": " << endl;
		solve();
	}
}
