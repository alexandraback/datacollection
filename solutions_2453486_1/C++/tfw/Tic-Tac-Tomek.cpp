#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char board[4][4];

bool gameOver(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if (board[i][j] == '.')
				return false;
		}
	}
	return true;
}

bool checkForWin(char player){
	// Horizontal
	for(int i = 0; i < 4; i++){
		bool win = true;
		for(int j = 0; j < 4; j++){
			if (board[i][j] != player && board[i][j] != 'T'){
				win = false;
				break;
			}
		}
		if (win)
			return true;
	}
	
	// Vertical
	for(int i = 0; i < 4; i++){
		bool win = true;
		for(int j = 0; j < 4; j++){
			if (board[j][i] != player && board[j][i] != 'T'){
				win = false;
				break;
			}
		}
		if (win)
			return true;
	}
	
	//Diagonals
	bool win = true;
	for(int i = 0; i < 4; i++){
		if(board[i][i] != player && board[i][i] != 'T'){
			win = false;
			break;
		}
	}
	if(win)
		return true;
	
	win = true;
	for(int i = 0; i < 4; i++){
		if(board[i][3-i] != player && board[i][3-i] != 'T'){
			win = false;
			break;
		}
	}
	if(win)
		return true;
		
	return false;
}

int main(){
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				char c; cin >> c;
				board[j][k] = c;
			}		
		}
		
		if(checkForWin('X')){
			cout << "Case #" << (i+1) << ": X won" << endl;
		} else if (checkForWin('O')){
			cout << "Case #" << (i+1) << ": O won" << endl;
		} else if (!gameOver()){
			cout << "Case #" << (i+1) << ": Game has not completed" << endl;
		} else {
			cout << "Case #" << (i+1) << ": Draw" << endl;
		}
	}
}
