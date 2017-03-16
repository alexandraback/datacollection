#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
	int T;
	char board[4][4];	
	cin >> T;

	for(size_t casen = 0; casen < T; ++casen){
		int e = 0, x , o;
		bool xwin = false, ywin = false;
		for(size_t i = 0; i < 4; ++i) {
			x = o = 0;
			for(size_t j = 0; j < 4; ++j) {
				cin >> board[i][j];
				if (board[i][j] == 'X') x++;
				if (board[i][j] == 'O') o++;
				if (board[i][j] == 'T') x++,o++;				
				if (board[i][j] == '.') e++;
			}
			if (x == 4) xwin = true;
			if (o == 4) ywin = true;
		}
		for(size_t j = 0; j < 4; ++j) {			
			x = o = 0;
			for(size_t i = 0; i < 4; ++i) {	
				if (board[i][j] == 'X') x++;
				if (board[i][j] == 'O') o++;
				if (board[i][j] == 'T') x++,o++;
				if (board[i][j] == '.') e++;
			}
			if (x == 4) xwin = true;
			if (o == 4) ywin = true;
		}
		x = o = 0;
		for(size_t i = 0; i < 4; ++i) {
			if (board[i][i] == 'X') x++;
			if (board[i][i] == 'O') o++;
			if (board[i][i] == 'T') x++,o++;	
		}
		if (x == 4) xwin = true;
		if (o == 4) ywin = true;
		
		x = o = 0;
		for(size_t i = 0; i < 4; ++i) {
			if (board[i][3-i] == 'X') x++;
			if (board[i][3-i] == 'O') o++;
			if (board[i][3-i] == 'T') x++,o++;
		}
		if (x == 4) xwin = true;
		if (o == 4) ywin = true;

		cout << "Case #" << casen+1 << ": ";
		if (xwin) cout << "X won" << endl;
		else if (ywin) cout << "O won" << endl;
		else if (e) cout << "Game has not completed" << endl;
		else cout << "Draw" << endl;
		
	}
	return 0;
}