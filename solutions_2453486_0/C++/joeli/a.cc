#include <iostream>
#include <string>

using namespace std;

bool winning_row(char player, char board[4][4], int row) {

	for (int x = 0; x < 4; ++x) {
		if (board[x][row] != player && board[x][row] != 'T') {
			return false;
		}
	}
	
	return true;
}

bool winning_column(char player, char board[4][4], int column) {

	for (int y = 0; y < 4; ++y) {
		if (board[column][y] != player && board[column][y] != 'T') {
			return false;
		}
	}
	
	return true;
}

bool winning_diagonal(char player, char board[4][4]) {

	int count = 0;

	for (int i = 0; i < 4; ++i) {
		if (board[i][i] == player || board[i][i] == 'T') {
			++count;
		}
	}

	if (count == 4) {
		return true;
	}

	count = 0;

	for (int i = 0; i < 4; ++i) {
		if (board[3-i][i] == player || board[3-i][i] == 'T') {
			++count;
		}
	}

	if (count == 4) {
		return true;
	}

	return false;
}

bool full(char board[4][4]) {
	
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			if (board[x][y] == '.') {
				return false;
			}
		}
	}
	
	return true;
}

bool won(char player, char board[4][4]) {

	for (int y = 0; y < 4; ++y) {
		if (winning_row(player, board, y)) {
			return true;
		}
	}

	for (int x = 0; x < 4; ++x) {
		if (winning_column(player, board, x)) {
			return true;
		}
	}

	if (winning_diagonal(player, board)) {
		return true;
	}

	return false;
}

string handle_case() {

	char board[4][4];

	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			cin >> board[x][y];
		}
	}

	if (won('X', board)) {
		return "X won";
	}
	else if (won('O', board)) {
		return "O won";
	}
	else if (full(board)) {
		return "Draw";
	}
	else {
		return "Game has not completed";
	}
}

int main(void) {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cout << "Case #" << i+1 << ": " << handle_case() << endl;
	}

	return 0;
}
