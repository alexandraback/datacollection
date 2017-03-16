#include <iostream>
#include <string>
using namespace std;
string board[4];
bool xWon, oWon;
void check(int i, int j, int di, int dj){
	bool x = true;
	bool o = true;
	for(int k = 0; k < 4; k++){
		x &= (board[i][j] == 'X' || board[i][j] == 'T');
		o &= (board[i][j] == 'O' || board[i][j] == 'T');
		i += di;
		j += dj;
	}
	xWon |= x;
	oWon |= o;
}
int main(){
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		for(int i = 0; i < 4; i++){
			cin >> board[i];
		}
		xWon = false;
		oWon = false;
		int emptyCells = 0;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(board[i][j] == '.') emptyCells++;
			}
		}
		for(int i = 0; i < 4; i++){
			check(i, 0, 0, 1);
			check(0, i, 1, 0);
		}
		check(0, 0, 1, 1);
		check(0, 3, 1, -1);
		cout << "Case #" << test << ": ";
		if(xWon)
			cout << "X won";
		else if(oWon)
			cout << "O won";
		else if (emptyCells > 0)
			cout << "Game has not completed";
		else
			cout << "Draw";
		cout << "\n";
	}
	return 0;
}
