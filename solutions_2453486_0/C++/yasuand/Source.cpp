#include<iostream>
#include<string>
using namespace std;

#define rep(i, from, to) for (i = from; i < to; ++i)

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	int i, j, k;
	rep (i, 0, t) {
		string board[4];
		rep (j, 0, 4) {
			cin >> board[j];
		}
		int xcnt = 0;
		int ocnt = 0;
		rep (j, 0, 4) {
			rep (k, 0, 4) {
				if (board[j][k] != 'X' && board[j][k] != 'T') {
					break;
				}
			}
			if (k == 4) {
				++xcnt;
			}
		}
		rep (j, 0, 4) {
			rep (k, 0, 4) {
				if (board[k][j] != 'X' && board[k][j] != 'T') {
					break;
				}
			}
			if (k == 4) {
				++xcnt;
			}
		}
		rep (j, 0, 4) {
			if (board[j][j] != 'X' && board[j][j] != 'T') {
				break;
			}
		}
		if (j == 4) {
			++xcnt;
		}
		rep (j, 0, 4) {
			if (board[j][3 - j] != 'X' && board[j][3 - j] != 'T') {
				break;
			}
		}
		if (j == 4) {
			++xcnt;
		}

		rep (j, 0, 4) {
			rep (k, 0, 4) {
				if (board[j][k] != 'O' && board[j][k] != 'T') {
					break;
				}
			}
			if (k == 4) {
				++ocnt;
			}
		}
		rep (j, 0, 4) {
			rep (k, 0, 4) {
				if (board[k][j] != 'O' && board[k][j] != 'T') {
					break;
				}
			}
			if (k == 4) {
				++ocnt;
			}
		}
		rep (j, 0, 4) {
			if (board[j][j] != 'O' && board[j][j] != 'T') {
				break;
			}
		}
		if (j == 4) {
			++ocnt;
		}
		rep (j, 0, 4) {
			if (board[j][3 - j] != 'O' && board[j][3 - j] != 'T') {
				break;
			}
		}
		if (j == 4) {
			++ocnt;
		}
		
		cout << "Case #" << i + 1;
		if (xcnt != 0) {
			cout << ": X won\n";
		} else if (ocnt != 0) {
			cout << ": O won\n";
		} else {
			int dcnt = 0;
			rep (j, 0, 4) {
				rep (k, 0, 4) {
					if (board[j][k] == '.') {
						++dcnt;
					}
				}
			}
			if (dcnt != 0) {
				cout << ": Game has not completed\n";
			} else {
				cout << ": Draw\n";
			}
		}
	}
	return 0;
}