#include <iostream>

using namespace std;

int t, r, c, m;
int a[1000][1000];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> r >> c >> m;
		int free = r * c - m;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = 0;
			}
		}
		cout << "Case #" << k << ": " << endl;
		if (free == 1) {
			for (int i = 0; i < r; i++, cout << endl) {
				for (int j = 0; j < c; j++) {
					if (!i && !j) cout << "c";
					else cout << "*";
				}
			}
		} else if (r == 1) {
			cout << "c";
			for (int i = 0; i < c - m - 1; i++) {
				cout << ".";
			}
			for (int i = 0; i < m; i++) {
				cout << "*";
			}
			cout << endl;
		} else if (c == 1) {
			cout << "c" << endl;
			for (int i = 0; i < r - m - 1; i++) {
				cout << "." << endl;
			}
			for (int i = 0; i < m; i++) {
				cout << "*" << endl;
			}
		} else if (r == 2) {
			if (m % 2 || free == 2) {
				cout << "Impossible" << endl;
			} else {
				for (int j = 0; j < free / 2; j++) {
					a[0][j] = a[1][j] = 1;
				}
				for (int i = 0; i < r; i++, cout << endl) {
					for (int j = 0; j < c; j++) {
						if (!i && !j) cout << "c";
						else if (a[i][j]) cout << ".";
						else cout << "*";
					}
				}
			}
		} else if (c == 2) {
			if (m % 2 || free == 2) {
				cout << "Impossible" << endl;
			} else {
				for (int i = 0; i < free / 2; i++) {
					a[i][0] = a[i][1] = 1;
				}
				for (int i = 0; i < r; i++, cout << endl) {
					for (int j = 0; j < c; j++) {
						if (!i && !j) cout << "c";
						else if (a[i][j]) cout << ".";
						else cout << "*";
					}
				}
			}
		} else {
			if (free == 1) {
				for (int i = 0; i < r; i++, cout << endl) {
					for (int j = 0; j < c; j++) {
						if (!i && !j) cout << "c";
						else cout << "*";
					}
				}
			} else if (free < 4) {
				cout << "Impossible" << endl;
			} else {
				free -= 4;
				int ar = 2;
				int ac = 2;
				while (free >= 4 && ar < r && ac < c) {
					free -= 4;
					ar++;
					ac++;
				}
				while (free >= 2 && ar < r) {
					free -= 2;
					ar++;
				}
				while (free >= 2 && ac < c) {
					free -= 2;
					ac++;
				}
				if (free == 1) {
					if (ar == 2 || ac == 2) {
						cout << "Impossible" << endl;
					} else {
						for (int i = 0; i < 2; i++) {
							for (int j = 0; j < ac; j++) {
								a[i][j] = 1;
							}
						}
						for (int i = 0; i < ar; i++) {
							for (int j = 0; j < 2; j++) {
								a[i][j] = 1;
							}
						}
						a[2][2] = 1;
						for (int i = 0; i < r; i++, cout << endl) {
							for (int j = 0; j < c; j++) {
								if (!i && !j) cout << "c";
								else if (a[i][j]) cout << ".";
								else cout << "*";
							}
						}
					}
				} else {
					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < ac; j++) {
							a[i][j] = 1;
						}
					}
					for (int i = 0; i < ar; i++) {
						for (int j = 0; j < 2; j++) {
							a[i][j] = 1;
						}
					}
					for (int i = 2; i < r; i++) {
						for (int j = 2; j < c; j++) {
							if (free) {
								a[i][j] = 1;
								free--;
							} else {
								break;
							}
						}
					}
					if (free > 0) {
						cout << "Impossible" << endl;
					} else {
						for (int i = 0; i < r; i++, cout << endl) {
							for (int j = 0; j < c; j++) {
								if (!i && !j) cout << "c";
								else if (a[i][j]) cout << ".";
								else cout << "*";
							}
						}
					}
				}
			}
		}
	}
}