#include <iostream>
#include <cstring>

using namespace std;

char g[50][50];

void printg(int r, int c) {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cout << g[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		cout << "Case #" << casenum << ":\n";
		int r, c, m;
		cin >> r >> c >> m;
		int s = r * c - m;
		// Trivial cases
		if (m == 0) { // No bomb
			cout << 'c' << string(c-1, '.') << '\n';
			for (int y=1; y<r; y++) cout << string(c, '.') << '\n';
		} else if (r == 1) { // Single row
			cout << 'c' << string(c-m-1, '.') << string(m, '*') << '\n';
		} else if (c == 1) { // Single column
			cout << "c\n";
			for (int i=0; i<r-m-1; i++) cout << ".\n";
			for (int i=0; i<m; i++) cout << "*\n";
		} else if (s == 1) { //Only one space
			cout << 'c' << string(c-1, '*') << '\n';
			for (int i=1; i<r; i++) cout << string(c, '*') << '\n';
		}
		// Hard cases
		// Odd number of spaces in grid of width or height 2 is impossible
		else if (min(r, c) == 2 && s % 2 == 1) {
			cout << "Impossible\n";
		}
		
		// Even number of spaces
		else if (s % 2 == 0 && s >= 4) {
			memset(g, '*', sizeof(g));
			g[0][1] = g[1][0] = g[1][1] = '.';
			g[0][0] = 'c';
			s -= 4;
			int x = 2;
			while (s > 0 && x < c) {
				g[0][x] = g[1][x] = '.';
				x += 1;
				s -= 2;
			}
			x = 0;
			int y = 2;
			while (s > 0 && y < r) {
				while (s > 0 && x + 1 < c) {
					g[y][x] = g[y][x+1] = '.';
					x += 2;
					s -= 2;
				}
				y++;
				x = 0;
			}
			y = 2;
			x = c - 1;
			while (s > 0) {
				g[y][x] = g[y+1][x] = '.';
				y += 2;
				s -= 2;
			}
			printg(r, c);
		}
		
		// Odd number of spaces with at least 9 spaces
		else if (s % 2 == 1 && s >= 9) {
			memset(g, '*', sizeof(g));
			for (int i=0; i<3; i++) for (int j=0; j<3; j++) g[i][j] = '.';
			g[0][0] = 'c';
			s -= 9;
			int x = 3;
			while (s > 0 && x < c) {
				g[0][x] = g[1][x] = '.';
				x += 1;
				s -= 2;
			}
			x = 3;
			int y = 2;
			while (s > 0 && y < r) {
				while (s > 0 && x + 1 < c) {
					g[y][x] = g[y][x+1] = '.';
					x += 2;
					s -= 2;
				}
				if (x == c) {
					if (g[y-1][x-1] == '*') swap(g[y-1][x-1], g[y][x-1]);
				}
				y++;
				x = 0;
			}
			y = 3;
			x = c - 1;
			while (s > 0) {
				g[y][x] = g[y+1][x] = '.';
				y += 2;
				s -= 2;
			}
			printg(r, c);
		}
		
		else {
			cout << "Impossible\n";
		}
	}
	return 0;
}