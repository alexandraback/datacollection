#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

// 0 = empty
// 1 = open
// 2 = has mine
unsigned char board[50][50];
int testcases,R,C,M;

bool check(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return true;
	return board[r][c] < 2;
}
void reveal(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return;
	board[r][c] = 1;
}

int main() {
	cin >> testcases;
	for (int tc = 1; tc <= testcases; tc++) {
		cin >> R >> C >> M;
		memset(board, 0, sizeof board);

		int r = 0, c = 0, effR=R, effC=C;
		for (int mn = M; mn; mn--) {
			board[r][c] = 2;
			if (effR >= effC) {
				// Add rows
				c++;
				if (c == C || (c == C-2 && mn == 2)) {
					c = C-effC;
					r++;
					effR--;
				}
			} else {
				// Add cols
				r++;
				if (r == R || (r == R-2 && mn == 2)) {
					r = R-effR;
					c++;
					effC--;
				}
			}
		}

		for (r = 0; r < R; r++) {
			for (c = 0; c < C; c++) {
				bool empty = (
					check(r-1,c-1) &&
					check(r-1,c) &&
					check(r-1,c+1) &&
					check(r,c-1) &&
					check(r,c) &&
					check(r,c+1) &&
					check(r+1,c-1) &&
					check(r+1,c) &&
					check(r+1,c+1)
				);
				if (empty) {
					reveal(r-1,c-1);
					reveal(r-1,c);
					reveal(r-1,c+1);
					reveal(r,c-1);
					reveal(r,c);
					reveal(r,c+1);
					reveal(r+1,c-1);
					reveal(r+1,c);
					reveal(r+1,c+1);
				}
			}
		}

		bool hasnonreveal = false;
		int nummines = 0;
		for (r = 0; r < R; r++) {
			for (c = 0; c < C; c++) {
				if (board[r][c] == 0) hasnonreveal = true;
				if (board[r][c] == 2) nummines++;
			}
		}

		if (nummines != M) {
			cout << "FAIL!!" << endl;
		}

		cout << "Case #" << tc << ":" << endl;
		if (hasnonreveal && M != R*C-1) {
			cout << "Impossible" << endl;
			continue;
		}

		for (r = 0; r < R; r++) {
			for (c = 0; c < C; c++) {
				if (r == R-1 && c == C-1) {
					cout << 'c';
					continue;
				}
				unsigned char val = board[r][c];
				cout << ((val==2) ? '*' : '.');
				//cout << char(val+'0');
			}
			cout << endl;
		}
	}
}
