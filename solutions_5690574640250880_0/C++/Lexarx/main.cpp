#include <cstdlib>
#include <iostream>

using namespace std;

#define S 50

int main() {
	int nt;
	cin >> nt;
	for (int t = 1; t <= nt; t++) {
		int r, c, m;
		cin >> r >> c >> m;
		bool reverse = false;
		if (r > c) {
			int t = r; r = c; c = t;
			reverse = true;
		}
		cout << "Case #" << t << ": " << endl;
		char a[S][S];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = '*';
			}
		}
		bool s = false;
		int n = r * c;
		int p = n - m;
		// c >= r
		if (p == 1) {
			s = true;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					a[i][j] = '.';
					p--;
					if (p == 0) {
						break;
					}
				}
				if (p == 0) {
					break;
				}
			}
			a[0][0] = 'c';
		} else if (r == 1) {
			s = true;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					a[i][j] = '.';
					p--;
					if (p == 0) {
						break;
					}
				}
				if (p == 0) {
					break;
				}
			}
			a[0][0] = 'c';
		} else if (p <= 3) {
			// Impossible
		} else if (r == 2) {
			if (p % 2 == 0) {
				s = true;
				for (int j = 0; j < c; j++) {
					for (int i = 0; i < r; i++) {
						a[i][j] = '.';
						p--;
						if (p == 0) {
							break;
						}
					}
					if (p == 0) {
						break;
					}
				}
				a[0][0] = 'c';
			}
		} else if (p == 7) {
			// Impossible
		} else {
			s = true;
			a[0][0] = 'c';
			a[0][1] = '.';
			a[1][0] = '.';
			a[1][1] = '.';
			p -= 4;
			int k = 2;
			int l = 1;
			while (p > 0) {
				if (k == c) {
					l++;
					k = 0;
				}
				if (l < 2) {
					if (p == 1) {
						s = false;
						break;
					} else if (p == 3) {
						a[l + 1][0] = '.';
						a[l + 1][1] = '.';
						a[l + 1][2] = '.';
						p -= 3;
					} else {
						a[0][k] = '.';
						a[1][k] = '.';
						p -= 2;
						k++;
					}
				} else if (p == 3 && k == c - 2) {
					if (k < 2) {
						s = false;
						break;
					}
					if (k == 2) { // case 4 4 3
						a[l][k] = '.';
						a[l + 1][0] = '.';
						a[l + 1][1] = '.';
					} else {
						a[l + 1][0] = '.';
						a[l + 1][1] = '.';
						a[l + 1][2] = '.';
					}
					p -= 3; 
				} else {
					a[l][k] = '.';
					p--;
					k++;
				}
			}
		}
		if (s) {
			if (reverse) {
				for (int i = 0; i < c; i++) {
					for (int j = 0; j < r; j++) {
						cout << a[j][i];
					}
					cout << endl;
				}
			} else {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						cout << a[i][j];
					}
					cout << endl;
				}
			}
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}