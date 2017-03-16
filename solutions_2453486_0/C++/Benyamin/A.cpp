// In The Name of God
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;

ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small-attempt0.out");
// 1: X __ 2: O __ 3: game not complete __ 4: draw
int t, num;
string s[5];
bool ans1, ans2;

bool win_X() {
	bool ans = false;
	int X, T;
	for(int i = 0; i < 4; ++i) {
		X = 0, T = 0;
		for(int j = 0; j < 4; ++j) {
			if(s[i][j] == 'X') X++;
			if(s[i][j] == 'T') T++;
		}
		if(X + T == 4 && T <= 1) ans = true;
	}
	for(int j = 0; j < 4; ++j) {
		X = 0, T = 0;
		for(int i = 0; i < 4; ++i) {
			if(s[i][j] == 'X') X++;
			if(s[i][j] == 'T') T++;
		}
		if(X + T == 4 && T <= 1) ans = true;
	}
	X = 0, T = 0;
	for(int i = 0; i < 4; ++i) {
		if(s[i][i] == 'X') X++;
		if(s[i][i] == 'T') T++;
	}
	if(X + T == 4 && T <= 1) ans = true;
	X = 0, T = 0;
	for(int i = 0; i < 4; ++i) {
		if(s[i][3 - i] == 'X') X++;
		if(s[i][3 - i] == 'T') T++;
	}
	if(X + T == 4 && T <= 1) ans = true;
	return ans;
}
bool win_O() {
	bool ans = false;
	int O, T;
	for(int i = 0; i < 4; ++i) {
		O = 0, T = 0;
		for(int j = 0; j < 4; ++j) {
			if(s[i][j] == 'O') O++;
			if(s[i][j] == 'T') T++;
		}
		if(O + T == 4 && T <= 1) ans = true;
	}
	for(int j = 0; j < 4; ++j) {
		O = 0, T = 0;
		for(int i = 0; i < 4; ++i) {
			if(s[i][j] == 'O') O++;
			if(s[i][j] == 'T') T++;
		}
		if(O + T == 4 && T <= 1) ans = true;
	}
	O = 0, T = 0;
	for(int i = 0; i < 4; ++i) {
		if(s[i][i] == 'O') O++;
		if(s[i][i] == 'T') T++;
	}
	if(O + T == 4 && T <= 1) ans = true;
	O = 0, T = 0;
	for(int i = 0; i < 4; ++i) {
		if(s[i][3 - i] == 'O') O++;
		if(s[i][3 - i] == 'T') T++;
	}
	if(O + T == 4 && T <= 1) ans = true;
	return ans;
}

void print(int c, int h) {
	cout << "Case #" << c << ": ";
	if(h == 1) cout << "X won" << endl;
	if(h == 2) cout << "O won" << endl;
	if(h == 3) cout << "Game has not completed" << endl;
	if(h == 4) cout << "Draw" << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		for(int j = 0; j < 4; ++j)
			cin >> s[j];
		bool ans1 = win_X();
		bool ans2 = win_O();
		num = 0;
		for(int j = 0; j < 4; ++j)
			for(int k = 0; k < 4; ++k)
				if(s[j][k] == '.')
					num++;
		if(ans1) {
			print(i, 1);
			continue;
		}
		if(ans2) {
			print(i, 2);
			continue;
		}
		if(num > 0) {
			print(i, 3);
			continue;
		}
		print(i, 4);
	}
	return 0;
}
