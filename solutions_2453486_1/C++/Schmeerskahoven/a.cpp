#include <iostream>
#include <string>

using namespace std;


bool wins(int board) {
	//horizontal paths
	if (
		(61440 == (61440 & board)) ||
		(3840 ==( 3840 & board)) ||
		(240 == (240 & board)) || 
		(15 == (15 & board)) )  {
		return true;
	}
	//vertical paths
	else if ((34952 == (34952 & board)) || (17476 == (17476 & board)) || (8738 == (8738 & board)) || (4369 == (4369 & board))) return true;
	//diagonals
 	else if ((33825 == (33825 & board)) || (4680 == (4680 & board))) return true;
	else return false;
}

int main() {
	int T;
	cin >> T;
	for (size_t kase = 1; kase <= T; ++kase) {
		cout << "Case #" << kase << ": ";
		char strings[4][4];
		int t_i, t_j;
		int x_board = 0;
		int o_board = 0;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				char c;
				cin >> ws >> c;
				strings[i][j] = c;
				x_board <<= 1;
				o_board <<= 1;
				if (c == 'T') {
					x_board += 1;
					o_board += 1;
				}
				else if (c == 'X') {
					x_board += 1;
				}
				else if (c == 'O') {
					o_board += 1;
				}
			}
		}
		bool o_wins = wins(o_board);
		bool x_wins = wins(x_board);						
//	cerr << "O board: " << o_board << endl;
//			cerr << "X board: " << x_board << endl;
	if (o_wins and x_wins) {
			cerr << "WTF" << endl;
					} else if (o_wins) {
			cout << "O won" << endl;
		} else if (x_wins) {
			cout << "X won" << endl;
		} else {
			if ((x_board | o_board) == 65535) {
				cout << "Draw" << endl;
			} else {
				cout << "Game has not completed" << endl;
			}
		}
	}	
}
