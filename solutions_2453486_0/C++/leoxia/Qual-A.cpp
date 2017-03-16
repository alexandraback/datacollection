#include <iostream>
#include <string>
using namespace std;

char board[4][4];
int dr[4] = {0, 1, 1, 1};
int dc[4] = {1, 0, 1, -1};

char checkwin(char *line) {
	//cout << "check: " << line << endl;
	char win = '.';
	for (int i = 0; i < 4; i++) {
		if (line[i] == '.') return '.';
		else if (line[i] == 'X') {
			if (win == 'O') return '.';
			else win = 'X';
		} else if (line[i] == 'O') {
			if (win == 'X') return '.';
			else win = 'O';
		}
	}
	return win;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// read the board
		bool full = true;
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				cin >> board[r][c];
				if (board[r][c] == '.') full = false;
			}
		}

		// determine the status
		char line[4], win = '.';
		int nr, nc;
		for (int r = 0; r < 4 && win == '.'; r++) {
			for (int c = 0; c < 4 && win == '.'; c++) {
				for (int d = 0; d < 4 && win == '.'; d++) {
					int i = 0;
					for (;i < 4; i++) {
						nr = r + dr[d] * i; nc = c + dc[d] * i;
						if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break;
						line[i] = board[nr][nc];
					}
					if (i >= 4) win = checkwin(line);
				}
			}
		}

		cout << "Case #" << t << ": ";
		if (win != '.') cout << win << " won" << endl;
		else if (!full) cout << "Game has not completed" << endl;
		else cout << "Draw" << endl;
	}
}