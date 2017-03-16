#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


int countSymbols(const vector<string>& board, char s) {
	int result = 0;
	for (size_t i = 0; i < board.size(); ++i) {
		for (size_t j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == s) {
				++result;
			}
		}
	}
	return result;
}

char isLine(const vector<string>& board, int i, int j, int di, int dj) {
	if (board[i][j] == '.') {
		return 0;
	}
	char s = board[i][j];
	for (int k = 1; k < 4; ++k) {
		char currS = board[i + di * k][j + dj * k];
		if (currS == 'T') {
			continue;
		} else if (currS == '.') {
			return 0;
		} else if (s == 'T') {
			s = currS;
		} else if (currS != s) {
			return 0;
		}
	}
	return s;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		char line[5];
		vector<string> board;
		cin.getline(line, 5);
		for (int i = 0; i < 4; ++i) {
			cin.getline(line, 5);
			board.push_back(line);
		}
		int dots = countSymbols(board, '.');
		bool xWins = false;
		bool yWins = false;

		// Check rows.
		for (size_t r = 0; r < 4; ++r) {
			char winner = isLine(board, r, 0, 0, 1);
			if (winner) {
				if (winner == 'X') {
					xWins = true;
					break;
				} else {
					yWins = true;
					break;
				}
			}
		}

		// Check cols.
		for (size_t cols = 0; cols < 4 && !xWins && !yWins; ++cols) {
			char winner = isLine(board, 0, cols, 1, 0);
			if (winner) {
				if (winner == 'X') {
					xWins = true;
				} else {
					yWins = true;
				}
			}
		}

		// Check diagonals
		if (!xWins && !yWins) {
			char winner = isLine(board, 0, 0, 1, 1);
			if (winner) {
				if (winner == 'X') {
					xWins = true;
				} else {
					yWins = true;
				}
			}
		}

		if (!xWins && !yWins) {
			char winner = isLine(board, 0, 3, 1, -1);
			if (winner) {
				if (winner == 'X') {
					xWins = true;
				} else {
					yWins = true;
				}
			}
		}

		string res;
		if (xWins) {
			res = "X won";
		} else if (yWins) {
			res = "O won";
		} else if (dots > 0) {
			res = "Game has not completed";
		} else {
			res = "Draw";
		}
		
		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}
