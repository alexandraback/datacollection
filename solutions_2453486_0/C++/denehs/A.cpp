#include <iostream>

using namespace std;

char board[10][10];

bool win (char in) {
	for (int i=0; i<4 && board[i][i]!='.'; i++) {
		if (board[i][i]!=in && board[i][i]!='T')
			break;
		if (i==3)
			return true;
	}

	for (int i=0; i<4 && board[i][3-i]!='.'; i++) {
		if (board[i][3-i]!=in && board[i][3-i]!='T')
			break;
		if (i==3)
			return true;
	}

	for (int i=0; i<4; i++) {
		for (int j=0; j<4 && board[i][j]!='.'; j++) {
			if (board[i][j]!=in && board[i][j]!='T')
				break;
			if (j==3)
				return true;
		}
	}

	for (int i=0; i<4; i++) {
		for (int j=0; j<4 && board[j][i]!='.'; j++) {
			if (board[j][i]!=in && board[j][i]!='T')
				break;
			if (j==3)
				return true;
		}
	}

	return false;
}


char check_win () {
	if (win('X'))
		return 'X';
	else if (win('O'))
		return 'O';
	else
		return '.';
}

int main () {
	int cases;

	cin >> cases;

	for (int c=1; c<=cases; c++) {
		cout << "Case #" << c << ": ";
		bool complete = true;

		cin.getline (board[0], 10);
		for (int i=0; i<4; i++) {
			cin.getline (board[i], 10);
		}

		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (board[i][j] == '.')
					complete = false;
			}
		}

		char winner = check_win ();

		if (winner=='X')
			cout << "X won";
		else if (winner=='O')
			cout << "O won";
		else if (!complete)
			cout << "Game has not completed";
		else
			cout << "Draw";
		cout << endl;

	}

	return 0;
}
