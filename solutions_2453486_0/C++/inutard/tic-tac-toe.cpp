#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

int T;
char board[4][4];

//1 if X won
//2 if O won
//0 if nobody won
int win_horizontal(int r) {
	int xc = 0, oc = 0, tc = 0;
	for (int c = 0; c < 4; c++) {
		xc += (board[r][c] == 'X');
		oc += (board[r][c] == 'O');
		tc += (board[r][c] == 'T');
	}
	if (xc + tc == 4) return 1;
	if (oc + tc == 4) return 2;
	return 0;
}

int win_vertical(int c) {
	int xc = 0, oc = 0, tc = 0;
	for (int r = 0; r < 4; r++) {
		xc += (board[r][c] == 'X');
		oc += (board[r][c] == 'O');
		tc += (board[r][c] == 'T');
	}
	if (xc + tc == 4) return 1;
	if (oc + tc == 4) return 2;
	return 0;
}

int win_diag() {
	int xc = 0, oc = 0, tc = 0;
	for (int c = 0; c < 4; c++) {
		xc += (board[c][c] == 'X');
		oc += (board[c][c] == 'O');
		tc += (board[c][c] == 'T');
	}
	if (xc + tc == 4) return 1;
	if (oc + tc == 4) return 2;
	return 0;
}

int win_otherdiag() {
	int xc = 0, oc = 0, tc = 0;
	for (int c = 0; c < 4; c++) {
		xc += (board[3-c][c] == 'X');
		oc += (board[3-c][c] == 'O');
		tc += (board[3-c][c] == 'T');
	}
	if (xc + tc == 4) return 1;
	if (oc + tc == 4) return 2;
	return 0;
}

#define go_state(s) if(s == 1){goto xwin;}else if(s == 2){goto owin;}

int main()
{
	cin >> T;
	for (int c = 1; c <= T; c++) {
		int used = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> board[i][j];
				if (board[i][j] != '.') used++;
			}
		}
		
		cout << "Case #" << c << ": ";
		
		int state;
		for (int r = 0; r < 4; r++) {
			state = win_horizontal(r);
			go_state(state);
		}
		
		for (int c = 0; c < 4; c++) {
			state = win_vertical(c);
			go_state(state);
		}
		
		state = win_diag();
		go_state(state);
		
		state = win_otherdiag();
		go_state(state);
		
		if (used == 16) goto draw;
		else goto notcomplete;
		
		xwin:
			cout << "X won" << endl;
			continue;
		owin:
			cout << "O won" << endl;
			continue;
		notcomplete:
			cout << "Game has not completed" << endl;
			continue;
		draw:
			cout << "Draw" << endl;
	}
	return 0;
}