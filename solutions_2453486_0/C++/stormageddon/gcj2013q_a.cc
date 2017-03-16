#include <iostream>
#include <string>

using namespace std;

enum state { INCOMPLETE,
	         NO_WINNER,
	         WINNER
};
typedef state RowState;

const int BOARDSIZE = 4;

RowState CheckLine(string line) {
	// A '.' indicates an incomplete row.
	if (line.find('.') != string::npos)
		return INCOMPLETE;

	// The row is full of X/O/T
	// Check for Xes.
	bool hasX = false;
	hasX = (line.find('X') != string::npos);
	// Check for Os
	bool hasO = false;
	hasO = (line.find('O') != string::npos);

	if (hasX && hasO)
		return NO_WINNER;
	if (hasX) {
		cout << "X won" << endl;
		return WINNER;
	}
	cout << "O won" << endl;
	return WINNER;
}

void CheckBoard(char board[][BOARDSIZE]) {
	bool full = true;
	// Check rows
	for (int i = 0; i < BOARDSIZE; i++) {
		string line;
		line.push_back(board[i][0]);
		line.push_back(board[i][1]);
		line.push_back(board[i][2]);
		line.push_back(board[i][3]);
		RowState result = CheckLine(line);
		if (result == WINNER)
			return;
		if (result == INCOMPLETE)
			full = false;
	}
	// Check columns
	for (int j = 0; j < BOARDSIZE; j++) {
		string line;
		line.push_back(board[0][j]);
		line.push_back(board[1][j]);
		line.push_back(board[2][j]);
		line.push_back(board[3][j]);
		RowState result = CheckLine(line);
		if (result == WINNER)
			return;
		if (result == INCOMPLETE)
			full = false;
	}
	// Check diagonals
	string forwardDiagonal;
	forwardDiagonal.push_back(board[0][0]);
	forwardDiagonal.push_back(board[1][1]);
	forwardDiagonal.push_back(board[2][2]);
	forwardDiagonal.push_back(board[3][3]);
	RowState result = CheckLine(forwardDiagonal);
	if (result == WINNER)
		return;
	if (result == INCOMPLETE)
		full = false;

	string backwardDiagonal;
	backwardDiagonal.push_back(board[0][3]);
	backwardDiagonal.push_back(board[1][2]);
	backwardDiagonal.push_back(board[2][1]);
	backwardDiagonal.push_back(board[3][0]);
	result = CheckLine(backwardDiagonal);
	if (result == WINNER)
		return;
	if (result == INCOMPLETE)
		full = false;

	// No winner, decide on draw or incomplete
	if (full) {
		cout << "Draw" << endl;
		return;
	}
	cout << "Game has not completed" << endl;
	return;
}

int main() {
	int numBoards = 0;
	cin >> numBoards;
	for (int boardNum = 1; boardNum <= numBoards; boardNum++) {
		// Read the next board.
		char board[BOARDSIZE][BOARDSIZE];
		for (int i = 0; i < BOARDSIZE; i++)
			for (int j = 0; j < BOARDSIZE; j++)
				cin >> board[i][j];

		cout << "Case #" << boardNum << ": ";
		CheckBoard(board);
	}

return 0;
}

