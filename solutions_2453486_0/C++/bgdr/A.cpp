#include<iostream>
#include<string>
using namespace std;

int main(){
	int T;
	cin >> T;
	string board[4];
	for(int c = 1; c <= T; ++c){
		int i;
		bool xwon = true, owon = true, incomplete = false;
		bool xwon2 = true, owon2 = true;
		for(int j = 0; j < 4; ++j) cin >> board[j];
		for(i = 0; i < 4; ++i) {
			if(board[i][i] == 'O') xwon = false;
			if(board[i][i] == 'X') owon = false;
			if(board[i][i] == '.') xwon = owon = false;
			if(board[i][3 - i] == 'O') xwon2 = false;
			if(board[i][3 - i] == 'X') owon2 = false;
			if(board[i][3 - i] == '.') xwon2 = owon2 = false;
		}
		string who = xwon || xwon2 ? "X" : "O";
		if(xwon2 || owon2 || xwon || owon){
				cout << "Case #" << c << ": " << who << " won" << endl;
				continue;
		}
		for(i = 0; i < 4; ++i) {
			int xs = 0, os = 0, ts = 0;
			int xs2 = 0, os2 = 0, ts2 = 0;
			for(int j = 0; j < 4; ++j) {
				if(board[i][j] == '.') incomplete = true;
				xs += board[i][j] == 'X';
				os += board[i][j] == 'O';
				ts += board[i][j] == 'T';
				xs2 += board[j][i] == 'X';
				os2 += board[j][i] == 'O';
				ts2 += board[j][i] == 'T';
			}
			if(xs + ts == 4 || xs2 + ts2 == 4) {
				cout << "Case #" << c << ": X won" << endl;
				break;
			}
			if(os + ts == 4 || os2 + ts2 == 4) {
				cout << "Case #" << c << ": O won" << endl;
				break;
			}
		}
		if(i == 4) {
				if(incomplete)
					cout << "Case #" << c << ": Game has not completed" << endl;
				else
					cout << "Case #" << c << ": Draw" << endl;
		}
	}
}
