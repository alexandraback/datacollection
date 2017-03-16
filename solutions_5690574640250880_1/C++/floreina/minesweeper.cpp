#include <iostream>
using namespace std;
char field[50][50];

void print(int r, int c) {
	field[0][c - 1] = 'c';
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			cout << field[i][j];
		}
		cout << endl;
	}
}

void solve_trivial(int r, int c, int m) {
	if(r == 2 && c >= 2 || c == 2 && r >= 2) {
		if(m % 2 != 0 || r * c - m < 4) {
			cout << "Impossible\n";
		} else {
			if(r == 2) {
				for(int cell = 0; m > 0; ++cell, m -= 2) {
					field[0][cell] = '*';
					field[1][cell] = '*';
				}
			} else {
				for(int row = r - 1; m > 0; --row, m -= 2) {
					field[row][0] = '*';
					field[row][1] = '*';
				}
			}
			print(r, c);
		}
	} else if(r == 1 && c >= 2 || c == 1 && r >= 2) {
		if(m + 2 > r * c) {
			cout << "Impossible\n";
		} else {
			if(r == 1) {
				for(int cell = 0; m > 0; ++cell, --m) {
					field[0][cell] = '*';
				}
			} else {
				for(int row = r - 1; m > 0; --row, --m) {
					field[row][0] = '*';
				}
			}
			print(r, c);
		}
	} else {
		if(m == 0) {
			print(r, c);
		} else {
			cout << "Impossible\n";
		}
	}
}

void decide(int r, int c, int left) {
	if(left == 2 || left == 4 || left > 5) {
		cout << "Impossible\n";
		return;
	}
	if(left >= 1) {
		field[2][c - 3] = '*';
	}
	if(left >= 3) {
		field[2][c - 2] = '*';
		field[2][c - 1] = '*';
	}
	if(left >= 5) {
		field[0][c - 3] = '*';
		field[1][c - 3] = '*';
	}
	print(r, c);
}
int laying(int r, int c, int left) {
	for(int cell = 0; cell + 3 < c; ++cell) {
		for(int row = 2; row >= 0; --row) {
			field[row][cell] = '*';
			left--;
			if(left == 0) {
				if(row == 1) {
					field[row][cell] = '.';
					field[2][cell + 1] = '*';
				}
				return 0;
			}
		}
	}
	return left;
}
int tiling(int r, int c, int left) {
	for(int row = r - 1; row >= 3; --row) {
		for(int cell = 0; cell < c; ++cell) {
			field[row][cell] = '*';
			left--;
			if(left == 0) {
				if(cell == c - 2) {
					field[row][cell] = '.';
					field[row - 1][0] = '*';
				}
				return 0;
			}
		}
	}
	return left;
}
void solve(int r, int c, int m) {
	int left = m;
	if(left == 0) {print(r, c); return;}
	left = tiling(r, c, left);
	if(left == 0) {print(r, c); return;}
	left = laying(r, c, left);
	if(left == 0) {print(r, c); return;}
	decide(r, c, left);
}
int main() {
	int T;
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int r, c, m;
		cin >> r >> c >> m;
		cout << "Case #" << t + 1 << ":\n";
		if(r * c == m + 1) {
			memset(field, '*', sizeof(field));
			print(r, c);
		} else {
			memset(field, '.', sizeof(field));
			if(r < 3 || c < 3) {
				solve_trivial(r, c, m);
			} else {
				solve(r, c, m);
			}
		}
	}
}