#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	int tc;
	cin >> tc;
	for (int c = 0; c < tc; c++) {
		cout << "Case #" << (c + 1) << ": ";
		vector<string> board;
		for (int i = 0; i < 4; i++) {
			string s;
			cin >> s;
			board.push_back(s);
		}
		bool completed = true;
		bool Owon = false;
		bool Xwon = false;
		for (int i = 0; i < 4; i++) {
			bool Xposs = true;
			bool Oposs = true;
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == '.') {
					completed = Xposs = Oposs = false;
				} else if (board[i][j] == 'X') {
					Oposs = false;
				} else if (board[i][j] == 'O') {
					Xposs = false;
				}
			}
			if (Xposs) Xwon = true;
			if (Oposs) Owon = true;
			Xposs = true;
			Oposs = true;
			for (int j = 0; j < 4; j++) {
				if (board[j][i] == '.') {
					completed = Xposs = Oposs = false;
				} else if (board[j][i] == 'X') {
					Oposs = false;
				} else if (board[j][i] == 'O') {
					Xposs = false;
				}
			}
			if (Xposs) Xwon = true;
			if (Oposs) Owon = true;
		}
		bool Xposs = true;
		bool Oposs = true;
		for (int j = 0; j < 4; j++) {
			if (board[j][j] == '.') {
				completed = Xposs = Oposs = false;
			} else if (board[j][j] == 'X') {
				Oposs = false;
			} else if (board[j][j] == 'O') {
				Xposs = false;
			}
		}
		if (Xposs) Xwon = true;
		if (Oposs) Owon = true;
		Xposs = true;
		Oposs = true;
		for (int j = 0; j < 4; j++) {
			if (board[3-j][j] == '.') {
				completed = Xposs = Oposs = false;
			} else if (board[3-j][j] == 'X') {
				Oposs = false;
			} else if (board[3-j][j] == 'O') {
				Xposs = false;
			}
		}
		if (Xposs) Xwon = true;
		if (Oposs) Owon = true;
		if (Xwon) cout << "X won" << endl;
		else if (Owon) cout << "O won" << endl;
		else if (!completed) cout << "Game has not completed" << endl;
		else cout << "Draw" << endl;
	}
	return 0;
}
