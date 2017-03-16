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
int GREEDY;

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
	if (f + TOT + GREEDY == R * C) {
		print(clickx, clicky);
		return 1;
	} else {
//		cout << "NO FOR " << f << " " << TOT << " " << GREEDY << " " << R *C << endl;
//		print(clickx, clicky);
//		cout << endl;
	}
	return 0;
}

int rec(int x, int y) {
	if (!TOT) {
		return fill();
	}
	if (x == R) {
		return 0;
	}

	int xx = x, yy = y+1;
	if (yy == C) {
		xx = x+1; yy = 0;
	}

	if (rec(xx,yy)) {
		return 1;
	}
	if(tab[x][y] != -2) return 0;

	tab[x][y] = -1;
	TOT--;
	GREEDY++;
	if (rec(xx,yy)) {
		return 1;
	}
	TOT++;
	GREEDY--;
	tab[x][y] = -2;
	return 0;
}

void brute() {
	int ans = rec(0, 0);
	if (!ans) {
		cout << "Impossible";
		cout << endl;
	}
}


void debugme(string mes) {
	// cout << "Debugging for " << mes << " TOT = " << TOT << " GG " << GREEDY << endl;
	// print(R-1, C-1);
	// cout << endl;
}

void greedy2() {
	if (C <= 2) {
		for(int i = 0; i< R; i++) {
			for(int j =0 ; j< C; j++) {
				if (TOT) {
					tab[i][j] = -1;
					TOT--;
					GREEDY++;
				}
			}
		}
	} else {
		for(int j =0 ; j< C; j++) {
			for(int i = 0; i< R; i++) {
				if (TOT) {
					tab[i][j] = -1;
					TOT--;
					GREEDY++;
				}
			}
		}
	}
	if(!TOT && fill()) {
		return;
	} else {
		debugme("Fail for case 2?");
	}
	cout << "Impossible" << endl;
}

void allButLast3by3() {
	// leave last 3 rol and cols
	for (int i = 0; i < R - 2; i++) {
		for (int j = 0; j < C - 2; j++) {
			if (i == R - 3 && j == C - 3) continue;
			if (TOT) {
				tab[i][j] = -1;
				TOT--;
				GREEDY++;
			}
		}
	}
	debugme("After first pass!");
}

void addWhenOdd() {
	if (TOT % 2 == 0) return;
	if (tab[R-3][C-3] == -2 && TOT) {
		tab[R-3][C-3] = -1;
		GREEDY++;
		TOT--;
	}
	debugme("LastWhenOdd");
}

void go2by2ButLast3Square() {
	for (int i = 0; i < R-2; i++) {
		for (int j = C-2; j < C; j++) {
			if (i == R-3 || j == C-3) continue;
			if (TOT) {
				tab[i][j] = -1;
				TOT--;
				GREEDY++;
			}
		}
	}
	for (int j = 0; j < C-2; j++) {
		for (int i = R-2; i < R; i++) {
			if (i == R-3 || j == C-3) continue;
			if (TOT) {
				tab[i][j] = -1;
				TOT--;
				GREEDY++;
			}
		}
	}
	debugme("After 2 by 2");
}

void greedy() {
	allButLast3by3();
	if(!TOT && fill()) return;

	addWhenOdd();
	if(!TOT && fill()) return;

	go2by2ButLast3Square();
	if(!TOT && fill()) return;

	// last 3x3
	brute();
}

void solve() {
	cin >> R >> C >> TOT;
	GREEDY = 0;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				tab[i][j] = -2;
				seen[i][j] = 0;
		}
  }
	if (R <= 2 || C <= 2) {
		greedy2();
	} else {
		greedy();
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
