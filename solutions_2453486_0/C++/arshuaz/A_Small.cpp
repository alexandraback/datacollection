#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string MP[4];

int Back(int R, int C, int DR, int DC, char CH) {
	if(R < 0 || R >= 4) return 0;
	if(C < 0 || C >= 4) return 0;
	if(MP[R][C] != CH && MP[R][C] != 'T') return 0;

	return 1 + Back(R+DR, C+DC, DR, DC, CH);
}

int main() {
	freopen("A_Small.in", "r", stdin);
	freopen("A_Small.out", "w", stdout);

	int T;
	cin >> T;

	for(int TC=1; TC<=T; TC++) {
		for(int i=0; i<4; i++) {
			cin >> MP[i];
		}

		int empty = 0;
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				empty += MP[i][j] == '.';
			}
		}

		bool Xwin = false;
		bool Owin = false;
		for(int i=0; i<4; i++) {
			if(Back(i, 0, 0, 1, 'X') == 4) Xwin = true;
			if(Back(0, i, 1, 0, 'X') == 4) Xwin = true;
			if(Back(i, 0, 0, 1, 'O') == 4) Owin = true;
			if(Back(0, i, 1, 0, 'O') == 4) Owin = true;
		}
		if(Back(0, 0, 1, 1, 'X') == 4) Xwin = true;
		if(Back(0, 3, 1, -1, 'X') == 4) Xwin = true;
		if(Back(0, 0, 1, 1, 'O') == 4) Owin = true;
		if(Back(0, 3, 1, -1, 'O') == 4) Owin = true;

		printf("Case #%d: ", TC);
		if(Xwin) printf("X won\n");
		else if(Owin) printf("O won\n");
		else if(empty > 0) printf("Game has not completed\n");
		else printf("Draw\n");
	}
}