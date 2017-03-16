#include <iostream>

using namespace std;

int zxcv(int i) {
	int X[4][4], O[4][4];
	int dots = 0;
	for(int y=0; y<4; y++) {
		for(int x=0; x<4; x++) {
			char s;
			cin >> s;
			if(s == 'X') {
				X[y][x] = 1;
				O[y][x] = 0;
			} else if(s == 'O') {
				X[y][x] = 0;
				O[y][x] = 1;
			} else if(s == '.') {
				X[y][x] = 0;
				O[y][x] = 0;
				dots = 1;
			} else {
				X[y][x] = 1;
				O[y][x] = 1;
			}
		}
	}
	if(X[0][0] && X[1][1] && X[2][2] && X[3][3] || X[0][3] && X[1][2] && X[2][1] && X[3][0]) {
		cout << "Case #" << i+1 << ": X won" << endl;
		return 1;
	}
	if(O[0][0] && O[1][1] && O[2][2] && O[3][3] || O[0][3] && O[1][2] && O[2][1] && O[3][0]) {
		cout << "Case #" << i+1 << ": O won" << endl;
		return 2;
	}
	for(int x=0; x<4; x++) {
		if(X[0][x] && X[1][x] && X[2][x] && X[3][x] || X[x][0] && X[x][1] && X[x][2] && X[x][3]) {
			cout << "Case #" << i+1 << ": X won" << endl;
			return 1;
		}
		if(O[0][x] && O[1][x] && O[2][x] && O[3][x] || O[x][0] && O[x][1] && O[x][2] && O[x][3]) {
			cout << "Case #" << i+1 << ": O won" << endl;
			return 2;
		}
	}
	if(dots) {
		cout << "Case #" << i+1 << ": Game has not completed" << endl;
		return 3;
	} else {
		cout << "Case #" << i+1 << ": Draw" << endl;
		return 4;
	}
}


int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		zxcv(i);
	}
}