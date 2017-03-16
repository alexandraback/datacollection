#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		string s[4];
		for (int i = 0; i < 4; ++i) {
			cin >> s[i];
		}

		cout << "Case #" << test << ": ";

		bool Xwin = false, Owin = false, Draw = true;
		for (int i = 0; i < 4; ++i) {
			{
				int xs = 0, os = 0, ts = 0;
				for (int j = 0; j < 4; ++j) {
					if (s[i][j] == 'X') ++xs;
					if (s[i][j] == 'O') ++os;
					if (s[i][j] == 'T') ++ts;
					if (s[i][j] == '.') Draw = false;
				}
				if (xs == 4 || (xs == 3 && ts == 1)) {
					Xwin = true;
				}
				if (os == 4 || (os == 3 && ts == 1)) {
					Owin = true;
				}
			}
			{
				int xs = 0, os = 0, ts = 0;
				for (int j = 0; j < 4; ++j) {
					if (s[j][i] == 'X') ++xs;
					if (s[j][i] == 'O') ++os;
					if (s[j][i] == 'T') ++ts;
					if (s[j][i] == '.') Draw = false;
				}
				if (xs == 4 || (xs == 3 && ts == 1)) {
					Xwin = true;
				}
				if (os == 4 || (os == 3 && ts == 1)) {
					Owin = true;
				}
			}

			{
				int xs = 0, os = 0, ts = 0;
				for (int j = 0; j < 4; ++j) {
					if (s[j][j] == 'X') ++xs;
					if (s[j][j] == 'O') ++os;
					if (s[j][j] == 'T') ++ts;
					if (s[j][j] == '.') Draw = false;
				}
				if (xs == 4 || (xs == 3 && ts == 1)) {
					Xwin = true;
				}
				if (os == 4 || (os == 3 && ts == 1)) {
					Owin = true;
				}
			}

			{
				int xs = 0, os = 0, ts = 0;
				for (int j = 0; j < 4; ++j) {
					if (s[j][3 - j] == 'X') ++xs;
					if (s[j][3 - j] == 'O') ++os;
					if (s[j][3 - j] == 'T') ++ts;
					if (s[j][3 - j] == '.') Draw = false;
				}
				if (xs == 4 || (xs == 3 && ts == 1)) {
					Xwin = true;
				}
				if (os == 4 || (os == 3 && ts == 1)) {
					Owin = true;
				}
			}
		}

		if (Xwin) {
			cout << "X won" << endl;
		} else if (Owin) {
			cout << "O won" << endl;
		} else if (Draw) {
			cout << "Draw" << endl;
		} else {
			cout << "Game has not completed" << endl;
		}
	}
	return 0;
}