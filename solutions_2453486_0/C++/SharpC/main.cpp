#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char won(const string& s)
{
	int x = count(s.begin(), s.end(), 'X'), o = count(s.begin(), s.end(), 'O'), t = count(s.begin(), s.end(), 'T');
	return x == 4 || x == 3 && t == 1 ? 'X' : o == 4 || o == 3 && t == 1 ? 'O' : 0;
}

string solve(const vector<string>& board)
{
	char w;
	for (int i = 0; i < 4; ++i) {
		if (w = won(board[i])) {
			return string(1, w) + " won"; 
		}
	}
	vector<string> s(6);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			s[i].push_back(board[j][i]);
		}
		s[4].push_back(board[i][i]);
		s[5].push_back(board[i][3-i]);
	}
	for (int i = 0; i < 6; ++i) {
		if (w = won(s[i])) {
			return string(1, w) + " won";
		}
	}
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) if (board[i][j] == '.') {
		return "Game has not completed";
	}
	return "Draw";
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {
		vector<string> board(4);
		string tmp;
		for (int i = 0; i < 4; ++i) {
			cin >> board[i];
		}
		getline(cin, tmp);
		cout << "Case #" << test + 1 << ": " << solve(board) << endl;
	}
}
