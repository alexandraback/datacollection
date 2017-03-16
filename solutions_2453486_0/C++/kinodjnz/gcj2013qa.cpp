#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

bool iswin(char b[8][8], int p) {
	for (int j = 0; j < 4; j++) {
		bool ok = true;
		for (int k = 0; k < 4; k++) {
			if (b[j][k] != p && b[j][k] != 'T') {
				ok = false;
				break;
			}
		}
		if (ok)
			return true;
	}
	for (int j = 0; j < 4; j++) {
		bool ok = true;
		for (int k = 0; k < 4; k++) {
			if (b[k][j] != p && b[k][j] != 'T') {
				ok = false;
				break;
			}
		}
		if (ok)
			return true;
	}
	bool ok = true;
	for (int k = 0; k < 4; k++) {
		if (b[k][k] != p && b[k][k] != 'T') {
			ok = false;
			break;
		}
	}
	if (ok)
		return true;
	ok = true;
	for (int k = 0; k < 4; k++) {
		if (b[k][3-k] != p && b[k][3-k] != 'T') {
			ok = false;
			break;
		}
	}
	if (ok)
		return true;
	return false;
}

bool isend(char b[8][8]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (b[i][j] == '.')
				return false;
		}
	}
	return true;
}

string solve(char b[8][8]) {
	if (iswin(b, 'X'))
		return "X won";
	if (iswin(b, 'O'))
		return "O won";
	if (isend(b))
		return "Draw";
	return "Game has not completed";
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		char b[8][8];
		for (int j = 0; j < 4; j++) {
			cin >> b[j];
		}
		string ans = solve(b);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
