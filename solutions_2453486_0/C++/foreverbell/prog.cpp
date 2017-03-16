
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int tests;
char mp[11][11];

int main() {
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-small-attempt0.out", "w", stdout);
	cin >> tests;
	for (int tt = 1; tt <= tests; ++tt) {
		bool done = true;
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				cin >> mp[i][j];
				if (mp[i][j] == '.') done = false;
			}
		}
		bool Owin = false, Xwin = false;
		for (int i = 1; i <= 4; ++i) {
			int Ocnt = 0, Xcnt = 0;
			for (int j = 1; j <= 4; ++j) {
				if (mp[i][j] == 'X') ++Xcnt;
				if (mp[i][j] == 'O') ++Ocnt;
				if (mp[i][j] == 'T') ++Xcnt, ++Ocnt;
			}
			if (Ocnt == 4) Owin = true;
			if (Xcnt == 4) Xwin = true;
		}
		for (int j = 1; j <= 4; ++j) {
			int Ocnt = 0, Xcnt = 0;
			for (int i = 1; i <= 4; ++i) {
				if (mp[i][j] == 'X') ++Xcnt;
				if (mp[i][j] == 'O') ++Ocnt;
				if (mp[i][j] == 'T') ++Xcnt, ++Ocnt;
			}
			if (Ocnt == 4) Owin = true;
			if (Xcnt == 4) Xwin = true;
		}
		int Ocnt = 0, Xcnt = 0;
		for (int i = 1; i <= 4; ++i) {
			if (mp[i][i] == 'X') ++Xcnt;
			if (mp[i][i] == 'O') ++Ocnt;
			if (mp[i][i] == 'T') ++Xcnt, ++Ocnt;
		}
		if (Ocnt == 4) Owin = true;
		if (Xcnt == 4) Xwin = true;
		Ocnt = 0, Xcnt = 0;
		for (int i = 1; i <= 4; ++i) {
			if (mp[i][5 - i] == 'X') ++Xcnt;
			if (mp[i][5 - i] == 'O') ++Ocnt;
			if (mp[i][5 - i] == 'T') ++Xcnt, ++Ocnt;
		}
		if (Ocnt == 4) Owin = true;
		if (Xcnt == 4) Xwin = true;
		printf("Case #%d: ", tt);
		if (Xwin) {
			puts("X won");
		} else if (Owin) {
			puts("O won");
		} else if (!done) {
			puts("Game has not completed");
		} else {
			puts("Draw");
		}
	}
	return 0;
}
