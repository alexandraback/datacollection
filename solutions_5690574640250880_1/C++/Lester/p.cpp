#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define sz(x) (int)(x).size()

typedef long long ll;

void init() {
	ios_base::sync_with_stdio(false);
}

char field[55][55];

void fill(int r, int c) {
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			field[i][j] = '.';
		}
	}	
}

void print(int r, int c) {
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			cout << field[i][j];
		}
		cout << '\n';
	}
}

void rotate(int r, int c) {
	char tmp[55][55];
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			tmp[j][i] = field[i][j];
		}
	}
	memcpy(field, tmp, 55 * 55 * sizeof(char));
}

bool solve(int r, int c, int m) {
	fill(r, c);

	if(r * c - 1 == m) {
		for(int i = 0;i < r;i++) {
			for(int j = 0;j < c;j++) {
				field[i][j] = '*';
			}
		}
		field[r - 1][c - 1] = 'c';
		return true;
	}

	if(min(r, c) == 1) {
		if(r * c - 2 < m) {
			return false;
		} else {
			for(int i = 0;i < r;i++) {
				for(int j = 0;j < c;j++) {
					if(m) {
						field[i][j] = '*';
						m--;
					} else {
						break;
					}
				}
			}
			field[r - 1][c - 1] = 'c';
			return true;
		}
	}

	if(r * c - 4 < m) {
		return false;
	}
	
	for(int i = 0;i < r - 2;i++) {
		for(int j = 0;j < c - 2;j++) {
			if(m) {
				field[i][j] = '*';
				m--;
			} else {
				break;
			}
		}
		if(m >= 2) {
			m -= 2;
			field[i][c - 2] = field[i][c - 1] = '*';
		}
	}
	if(m == 1 && r >= 3 && c >= 4 &&
		field[r - 3][c - 1] == '.' && field[r - 3][c - 2] == '.') {
		assert(field[r - 3][c - 3] == '*');
		field[r - 3][c - 3] = '.';
		m++;
	} else if(m % 2 == 1) {
		return false;
	}
	for(int j = 0;j < m / 2;j++) {
		field[r - 2][j] = field[r - 1][j] = '*';
	}
	field[r - 1][c - 1] = 'c';
	return true;
}

bool solve2(int r, int c, int m) {
	m = r * c - m;
	for(int k = 2;k * k <= m;k++) {
		if(m % k == 0 && k <= r && m / k <= c) {
			for(int i = 0;i < r;i++) {
				for(int j = 0;j < c;j++) {
					field[i][j] = (i < k && j < m / k ? '.' : '*');
				}
			}
			field[0][0] = 'c';
			return true;
		}
	}
	return false;
}

int main() {
	init();
	int tests;
	cin >> tests;
	for(int t = 1;t <= tests;t++) {
		int r, c, m;
		cin >> r >> c >> m;
		cout << "Case #" << t << ":\n";
		if(solve(r, c, m)) {
			print(r, c);
		} else if(solve(c, r, m)) {
			rotate(c, r);
			print(r, c);
		} else if(solve2(r, c, m)) {
			print(r, c);
		} else if(solve2(c, r, m)) {
			rotate(c, r);
			print(r, c);
		} else {
			cout << "Impossible\n";
		}
	}
	return 0;
}
