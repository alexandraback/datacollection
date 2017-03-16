#include <string>
#include <iostream>
using namespace std;

#define handle(a, b, c, d) do {\
	string s = "";\
	s += a;\
	s += b;\
	s += c;\
	s += d;\
	char ret = check(s);\
	switch (ret) {\
		case 'X': cout << "X won\n"; return;\
		case 'O': cout << "O won\n"; return;\
		default: break;\
	}\
} while (0)

int T;
string a[4];

char check(const string & s) {
	bool succ;
	succ = true;
	for (int i = 0; i < 4; i++) {
		if (!(s[i] == 'O' || s[i] == 'T')) {
			succ = false;
			break;
		}
	}
	if (succ) {
		return 'O';
	}
	succ = true;
	for (int i = 0; i < 4; i++) {
		if (!(s[i] == 'X' || s[i] == 'T')) {
			succ = false;
			break;
		}
	}
	if (succ) {
		return 'X';
	}
	return 'D';
}

void solve() {
	handle(a[0][0], a[1][1], a[2][2], a[3][3]);
	handle(a[0][3], a[1][2], a[2][1], a[3][0]);
	for (int i = 0; i < 4; i++) {
		handle(a[i][0], a[i][1], a[i][2], a[i][3]);
	}
	for (int j = 0; j < 4; j++) {
		handle(a[0][j], a[1][j], a[2][j], a[3][j]);
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == '.') {
				sum++;
			}
		}
	}
	if (sum == 0) {
		cout << "Draw\n";
	} else {
		cout << "Game has not completed\n";
	}
}

int main() {
	cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		cout << "Case #" << ca << ": ";
		for (int i = 0; i < 4; i++) {
			cin >> a[i];
		}
		solve();
	}
	return 0;
}
