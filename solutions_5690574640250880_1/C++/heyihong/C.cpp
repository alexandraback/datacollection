#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N(55);

int ca, C, r, c, m, rem;
char a[N][N];

void output() {
	a[0][0] = 'c';
	for (int i = 0; i != r; ++i) {
		for (int j = 0; j != c; ++j)
			cout << a[i][j];
		cout << endl;
	}
}

void solve() {
	int x = 0, y = 0;
	for (int d = 0; ; ++d) {
		for (int i = 0; i != r; ++i)
			for (int j = 0; j != c; ++j)
				if (i <= d && j <= d && rem && a[i][j] != '.') {
					a[i][j] = '.'; --rem;
					if (rem == 0) {
						if (d && (i == 0 || j == 0)) {
							if (i == 0) swap(a[x][y], a[1][j]);
							else swap(a[x][y], a[i][1]);
						}
						return;
					}
					if (x + y < i + j) {
						x = i; y = j;
					}
				}
	}
}

int main() {
	freopen("in.txt", "r" ,stdin);
	cin >> ca;
	for (int C = 1; C <= ca; ++C) {
		cin >> r >> c >> m;
		cout << "Case #" << C << ":" << endl;
		rem = r * c - m;
		for (int i = 0; i != r; ++i)
			for (int j = 0; j != c; ++j)
				a[i][j] = '*';
		if (r == 1 || c == 1 || rem == 1) {
			for (int i = 0; i != r; ++i)
				for (int j = 0; j != c; ++j)
					if (rem) {
						a[i][j] = '.'; --rem;
					}
			output();
		}
		else if (r == 2 || c == 2) {
			if (rem == 2 || rem % 2) {
				cout << "Impossible" << endl;
				continue;
			}
			if (r == 2) {
				for (int i = 0; i != c && rem; ++i) {
					a[0][i] = a[1][i] = '.'; rem -= 2;
				}
			}
			else {
				for (int i = 0; i != r && rem; ++i) {
					a[i][0] = a[i][1] = '.'; rem -= 2;
				}
			}
			output();
		}
		else {
			if (rem == 2 || rem == 3 || rem == 5 || rem == 7) {
				cout << "Impossible" << endl;
				continue;
			}
			solve();
			output();
		}
	}
	return 0;
}