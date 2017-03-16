#include<cstring>
#include<string>
#include<iostream>
#include<set>
#include<string>
#include<sstream>
#include <iomanip>
using namespace std;

#define NN 64
int tab[NN][NN], seen[NN][NN];
int R,C,TOT;

int neigh(int x, int y) {
	for(int i = x-1; i <= x+1; i++) {
		for(int j = y-1; j <= y+1; j++) {
			if (i < 0 || i >= R || j < 0 || j >= C) {
				continue;
			}
			if (i == x && j == y) continue;
			if (tab[i][j] == -1) {
				return 1;
			}
		}
	}
	return 0;
}

int flood(int x, int y) {
	if (x < 0 || x >= R || y < 0 || y >= C) return 0;
	if (tab[x][y] == -1) return 0;
	if (seen[x][y]) {
		return 0;
	}
	seen[x][y] = 1;
	if (neigh(x,y)) return 1;

	int ok = 1;
	for(int i = x-1; i <= x+1; i++) {
		for(int j = y-1; j <= y+1; j++) {
			ok += flood(i,j);
		}
	}
	return ok;
}

void print(int x, int y) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == x && j == y) {
				if (tab[i][j] == -1) {
					printf("C"); // DEBUG
				} else {
					printf("c");
				}
			} else if (tab[i][j] == -1) {
				printf("*");
			} else printf(".");
		}
		printf("\n");
	}
}

int fill() {
	int clickx = -1, clicky = -1;
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			seen[i][j] = 0;
			if (tab[i][j] == -2) {
				if (clickx == -1 || !neigh(i, j)) {
					clickx = i; clicky = j;
				}
			}
		}
  }
	int f = flood(clickx, clicky);
	if (f + TOT == R * C) {
		print(clickx, clicky);
		return 1;
	} else {
//		cout << "NO FOR " << f << " " << TOT << " " << R *C << endl;
//		print(clickx, clicky);
//		cout << endl;
	}
	return 0;
}

int rec(int x, int y, int sobra) {
	if (sobra == 0) {
		return fill();
	}
	if (x == R) {
		return 0;
	}
	int xx = x, yy = y+1;
	if (yy == C) {
		xx = x+1; yy = 0;
	}
	if (rec(xx,yy,sobra)) {
		return 1;
	} else {
		tab[x][y] = -1;
		if (rec(xx,yy,sobra-1)) {
			return 1;
		}
		tab[x][y] = -2;
		return 0;
	}
}

void begindebug() {
	return; // DEBUG
	cout << R << " " << C << " " << TOT << endl;
	for (int i = 0; i<R; i++) {
		for (int j = 0;j<C; j++) {
			printf("%d" , tab[i][j] );
		}
		cout << endl;
	}
	cout << endl;
}

void solve() {
	cin >> R >> C >> TOT;
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			tab[i][j] = -2;
			seen[i][j] = 0;
		}
  }
	begindebug();
	int ans = rec(0, 0, TOT);
	if (!ans) {
		cout << "Impossible";
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}
