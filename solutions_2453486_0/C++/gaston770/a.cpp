#include <iostream>
#include <string>

using namespace std;

bool won(char player, string board[4]) {
	for (int j = 0; j < 4; j++) {
		bool w = true;
		for (int i = 0; i < 4; i++)
			w = w && ((board[j][i] == player) || (board[j][i] == 'T'));
		if (w) return true;
	}
	for (int j = 0; j < 4; j++) {
		bool w = true;
		for (int i = 0; i < 4; i++)
			w = w && ((board[i][j] == player) || (board[i][j] == 'T'));
		if (w) return true;
	}
	bool w = true;
	for (int i = 0; i < 4; i++) {
		w = w && ((board[i][i] == player) || (board[i][i] == 'T'));
	}
	if (w) return true;
	w = true;
	for (int i = 0; i < 4; i++) {
		w = w && ((board[i][3-i] == player) || (board[i][3-i] == 'T'));
	}
	if (w) return true;
	return false;
}

int main () {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i+1 << ": ";

		string board[4];
		for (int i = 0; i < 4; i++) cin >> board[i];

		if (won('O', board)) {
			cout << "O won" << endl;
			continue;
		}
		if (won('X', board)) {
			
			cout << "X won" << endl;
			continue;
		}
		bool uncomplete = false;
		for (int j = 0; j < 4 && !uncomplete; j++) if (board[j].find(".") != string::npos) {
			uncomplete = true;
			cout << "Game has not completed" << endl;
		}
		if (!uncomplete) cout << "Draw" << endl;
	}
	return 0;
}
