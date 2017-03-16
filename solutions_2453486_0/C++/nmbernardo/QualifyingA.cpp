/*
 * QualifyingA.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: Neil
 */



#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define X_WIN 0
#define DRAW -1
#define O_WIN 1
#define INC 2


int T;


string grid[4];



//draw - 0, X - 1, O - 2

int solve() {


	int diag_check = 1;

	//horizontal X
	for(int i = 0; i < 4; i++) {

		int X_win = 1;

		for(int j = 0; j < 4; j++) {
			if(grid[i][j] != 'X' && grid[i][j] != 'T') {
				X_win = 0;
			}
		}


		if(X_win)
			return X_WIN;
	}


	//vertical X

	for(int i = 0; i < 4; i++) {
		int X_win = 1;

		for(int j = 0; j < 4; j++) {

			if(grid[j][i] != 'X' && grid[j][i] != 'T') {
				X_win = 0;
			}
		}

		if(X_win)
			return X_WIN;
	}


	//diagonal X


	diag_check = 1;

	for(int i = 0; i < 4; i++) {
		if(grid[i][i] != 'X' && grid[i][i] != 'T' ) {
			diag_check = 0;
			break;
		}
	}

	if(diag_check) {
		return X_WIN;
	}


	diag_check = 1;

	for(int i = 0; i < 4; i++) {
		if(grid[i][3 - i] != 'X' && grid[i][3 - i] != 'T') {
			diag_check = 0;
			break;
		}
	}

	if(diag_check)
		return X_WIN;





	//horizontal O
		for(int i = 0; i < 4; i++) {

			int O_win = 1;

			for(int j = 0; j < 4; j++) {
				if(grid[i][j] != 'O' && grid[i][j] != 'T') {
					O_win = 0;
				}
			}


			if(O_win)
				return O_WIN;
		}


		//vertical X

		for(int i = 0; i < 4; i++) {
			int O_win = 1;

			for(int j = 0; j < 4; j++) {

				if(grid[j][i] != 'O' && grid[j][i] != 'T') {
					O_win = 0;
				}
			}

			if(O_win)
				return O_WIN;
		}


		//diagonal X


		diag_check = 1;

		for(int i = 0; i < 4; i++) {
			if(grid[i][i] != 'O' && grid[i][i] != 'T' ) {
				diag_check = 0;
				break;
			}
		}

		if(diag_check) {
			return O_WIN;
		}


		diag_check = 1;

		for(int i = 0; i < 4; i++) {
			if(grid[i][3 - i] != 'O' && grid[i][3 - i] != 'T') {
				diag_check = 0;
				break;
			}
		}

		if(diag_check)
			return O_WIN;





		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(grid[i][j] == '.') {
					return INC;
				}
			}
		}

		return DRAW;




}

int main() {


	freopen("test.in","r",stdin);

	cin >> T;

	for(int t = 1;t<= T; t++) {




		for(int i = 0; i < 4; i++) {
			cin >> grid[i];
		}



		cout << "Case #" << t << ": ";



		int win = solve();


			if(win == O_WIN) {
				cout << "O won" << endl;
			} else if(win == X_WIN) {
				cout << "X won" << endl;
			} else if(win == DRAW){
				cout << "Draw" << endl;
			} else{
				cout << "Game has not completed" << endl;
			}




	}


	return 0;
}



