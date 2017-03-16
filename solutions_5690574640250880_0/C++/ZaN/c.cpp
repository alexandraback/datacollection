#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		char s[50][50];
		int r, c, m;
		cin >> r >> c >> m;
		int f = r*c - m;

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				s[i][j] = '.';
			}
		}
		cout << "Case #" << test << ":" << endl;
		if (r == 1) {
			for (int j = c - m; j < c; ++j) {
				s[0][j] = '*';
			}
			s[0][0] = 'c';
		} else if (c == 1) {
			for (int i = r - m; i < r; ++i) {
				s[i][0] = '*';
			}
			s[0][0] = 'c';
		} else if (f == 0) {
			s[0][0] = 'c';
		} else if (f == 1) {
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					s[i][j] = (i == 0 && j == 0 ? 'c' : '*');
				}
			}
		} else if (r == 2) {
			if (f == 2 || m % 2 != 0) {
				cout << "Impossible" << endl;
				continue;
			}
			for (int i = 0; i < r; ++i) {
				for (int j = c - m / 2; j < c; ++j) {
					s[i][j] = '*';
				}
			}
			s[0][0] = 'c';
		} else if (c == 2) {
			if (f == 2 || m % 2 != 0) {
				cout << "Impossible" << endl;
				continue;
			}
			for (int i = r - m / 2; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					s[i][j] = '*';
				}
			}
			s[0][0] = 'c';
		} else {
			if (f == 2 || f == 3 || f == 5 || f == 7) {
				cout << "Impossible" << endl;
				continue;
			}
			int r1 = r, m1 = m;
			while (r1 > 3 && m1 >= c) {
				for (int j = 0; j < c; ++j) {
					s[r1 - 1][j] = '*';
				}
				--r1;
				m1 -= c;
			}
			if (r1 > 3 && m1 > 0) {
				if (m1 <= c - 2) {
					for (int j = c - m1; j < c; ++j) {
						s[r1 - 1][j] = '*';
					}
					m1 = 0;
				} else {
					for (int j = 2; j < c; ++j) {
						s[r1 - 1][j] = '*';
					}
					s[r1 - 2][c - 1] = '*';
					m1 = 0;
				}
			}
			int c1 = c;
			while (c1 > 3 && m1 >= 3) {
				for (int i = 0; i < 3; ++i) {
					s[i][c1 - 1] = '*';
				}
				--c1;
				m1 -= 3;
			}
			if (c1 > 3 && m1 > 0) {
				if (m1 == 1) {
					s[2][c1 - 1] = '*';
					m1 = 0;
				} else {
					s[2][c1 - 1] = '*';
					s[2][c1 - 2] = '*';
					m1 = 0;
				}
			}
			if (m1 == 1) {
				s[2][2] = '*';
			} else if (m1 == 3) {
				s[0][2] = s[1][2] = s[2][2] = '*';
			} else if (m1 == 5) {
				s[0][2] = s[1][2] = s[2][2] = '*';
				s[2][0] = s[2][1] = '*';
			}
			s[0][0] = 'c';
		}

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cout << s[i][j];
			}
			cout << endl;
		}
	}
}
