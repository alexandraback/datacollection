#include <iostream>
#include <string>
using namespace std;

#define RT freopen("a.in", "r", stdin)
#define WT freopen("b.out", "w", stdout)
	

string Grid[4];

bool isWin(char Curr) {
	int C;
	for(int i = 0; i < 4; ++i) {
		C = 0;
		for(int j = 0; j < 4; ++j) {
			if(Grid[i][j] == Curr || Grid[i][j] == 'T') ++C;
		}
		if(C == 4) return true;
	}
	for(int i = 0; i < 4; ++i) {
		C = 0;
		for(int j = 0; j < 4; ++j) {
			if(Grid[j][i] == Curr || Grid[j][i] == 'T') ++C;
		}
		if(C == 4) return true;
	}
	C = 0;
	for(int i = 0; i < 4; ++i) {
		if(Grid[i][i] == Curr || Grid[i][i] == 'T') ++C;
	}
	if(C == 4) return true;
	C = 0;
	for(int i = 0, j = 3; i < 4 && j >= 0; ++i, --j) {
		if(Grid[i][j] == Curr || Grid[i][j] == 'T') ++C;
	}
	if(C == 4) return true;
	return false;
}

bool isDrow() {
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(Grid[i][j] == '.')
				return false;
	return true;
}

int main() {
	RT; WT;
	int cases; cin >> cases;
	for(int c = 0; c < cases; ++c) {
		for(int i = 0; i < 4; ++i) cin >> Grid[i];
		cout << "Case #" << c + 1 << ": ";
		if(isWin('X')) cout << "X won" << endl;
		else if(isWin('O')) cout << "O won" << endl;
		else if(isDrow()) cout << "Draw" << endl;
		else cout << "Game has not completed" << endl;
	}
	return 0;
}