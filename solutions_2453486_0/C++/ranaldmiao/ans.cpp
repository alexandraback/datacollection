#include <cstdio>
#include <iostream>
using namespace std;
int n=4, tc;
char s[20][20];
int checkRow (int r) {
	int x=0, o=0, t=0;
	for (int i = 0; i < n; ++i) {
		if (s[i][r] == '.') return 0;
		if (s[i][r] == 'X') ++x;
		if (s[i][r] == 'O') ++o;
		if (s[i][r] == 'T') ++t;
	}
	if (x + t == 4) return 1;
	if (o + t == 4) return 2;
	return 0;
}

int checkCol (int c) {
	int x=0, o=0, t=0;
	for (int i = 0; i < n; ++i) {
		if (s[c][i] == '.') return 0;
		if (s[c][i] == 'X') ++x;
		if (s[c][i] == 'O') ++o;
		if (s[c][i] == 'T') ++t;
	}
	if (x + t == 4) return 1;
	if (o + t == 4) return 2;
	return 0;
}
int checkDiagonal (int d) {
	int x=0, o=0, t=0;
	if (d == 0) {
		for (int i = 0; i < n; ++i) {
			if (s[i][i] == '.') return 0;
			if (s[i][i] == 'X') ++x;
			if (s[i][i] == 'O') ++o;
			if (s[i][i] == 'T') ++t;
		}
		if (x + t == 4) return 1;
		if (o + t == 4) return 2;
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (s[i][3-i] == '.') return 0;
			if (s[i][3-i] == 'X') ++x;
			if (s[i][3-i] == 'O') ++o;
			if (s[i][3-i] == 'T') ++t;
		}
		if (x + t == 4) return 1;
		if (o + t == 4) return 2;
	}
	return 0;
}
int main () {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		for (int i = 0; i < n; ++i) scanf("%s", s[i]);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, checkRow(i));
			ans = max(ans, checkCol(i));
			if (i < 2) ans = max(ans, checkDiagonal(i));
		}
		printf("Case #%d: ", t);
		if (ans == 0) {
			bool filled = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (s[i][j] == '.') filled = false;
				}
			}
			if (!filled) printf("Game has not completed\n");
			else printf("Draw\n");
		}
		else if (ans == 1) printf("X won\n");
		else if (ans == 2) printf("O won\n");
	}
}