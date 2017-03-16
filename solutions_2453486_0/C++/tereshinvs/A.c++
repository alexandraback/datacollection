#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool won(vector<string> b, char c) {
	for (int i = 0; i < 4; i++) {
		bool res = true;
		for (int j = 0; j < 4; j++)
			if (b[i][j] != c && b[i][j] != 'T')
				res = false;
		if (res)
			return true;
	}

	for (int i = 0; i < 4; i++) {
		bool res = true;
		for (int j = 0; j < 4; j++)
			if (b[j][i] != c && b[j][i] != 'T')
				res = false;
		if (res)
			return true;
	}

	bool res = true;
	for (int i = 0; i < 4; i++)
		if (b[i][i] != c && b[i][i] != 'T')
			res = false;
	if (res)
		return true;

	res = true;
	for (int i = 0; i < 4; i++)
		if (b[3 - i][i] != c && b[3 - i][i] != 'T')
			res = false;
	if (res)
		return true;

	return false;
}

bool is_there_empty_places(vector<string> b) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (b[i][j] == '.')
				return true;
	return false;
}

int main() {
	int n;
	cin >> n;

	for (int q = 0; q < n; q++) {
		vector<string> board(4);
		cin >> board[0] >> board[1] >> board[2] >> board[3];

		cout << "Case #" << q + 1 << ": ";
		if (won(board, 'X'))
			cout << "X won";
		else if (won(board, 'O'))
			cout << "O won";
		else if (is_there_empty_places(board))
			cout << "Game has not completed";
		else
			cout << "Draw";
		cout << endl;
	}
}