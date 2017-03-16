#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

#pragma comment(linker, "/STACK:64000000")

int n;
char field[8][8];

void read_field() {
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			field[i][j] = s[j];
		}
	}
}
bool isWin(char player) {
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		bool was = false;
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == player) cnt++;
			if (field[i][j] == 'T' && !was) {
				was = true;
				cnt++;
			}
		}
		if (cnt == 4) return true;
	}
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		bool was = false;
		for (int j = 0; j < 4; j++) {
			if (field[j][i] == player) cnt++;
			if (field[j][i] == 'T' && !was) {
				was = true;
				cnt++;
			}
		}
		if (cnt == 4) return true;
	}
	int cnt = 0;
	bool was = false;
	for (int i = 0; i < 4; i++) {
		if (field[i][i] == player) cnt++;
		if (field[i][i] == 'T' && !was) {
			was = true;
			cnt++;
		}
	}
	if (cnt == 4) return true;
	cnt = 0; was = false;
	for (int i = 0; i < 4; i++) {
		if (field[i][3 - i] == player) cnt++;
		if (field[i][3 - i] == 'T' && !was) {
			was = true;
			cnt++;
		}
	}
	if (cnt == 4) return true;
	return false;
}
bool isEmpty() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == '.') return true;
		}
	}
	return false;
}
int main() {
	//freopen("in.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		read_field();
		cout << "Case #" << i + 1 << ": ";
		if (isWin('X')) {
			cout << "X won";
		}
		else if (isWin('O')) {
			cout << "O won";
		}
		else if (isEmpty()) {
			cout << "Game has not completed";
		}
		else {
			cout << "Draw";
		}
		cout << endl;
	}

	return 0;
}