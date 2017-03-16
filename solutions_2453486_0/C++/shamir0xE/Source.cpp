#include <iostream>
#include <map>
#include <stdio.h>
#include <set>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <list>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
/**
 * @author:	Shamir14 -- Amirhossein Shapoori
 * lordamir14@gmail.com
 * ACM team: AnotherChorMangz
 * Tehran, Iran
 * Still listening to Mark Knopfler...
 * :P
 */

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test, t, i, j, Xcnt, T_x, T_y, Ocnt, win;
	char board[10][10];
	bool incomplete;

	cin >> test;
	t = 0;
	
	while(test--){
		incomplete = false;
		win = 2;

		for(i = 0; i < 4; i++)
			cin >> board[i];
		
		T_x = T_y = -1;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++){
				if(board[i][j] == 'T')
					T_x = i, T_y = j;
				if(board[i][j] == '.')
					incomplete = true;
			}

		// first: T = X
		
		if(T_x != -1)
			board[T_x][T_y] = 'X';

			// row action
		for(i = 0; i < 4; i++){
			Xcnt = Ocnt = 0;
			for(j = 0; j < 4; j++){
				if(board[i][j] == 'X') Xcnt++;
				if(board[i][j] == 'O') Ocnt++;
			}
			if(Xcnt == 4) win = 0;
			if(Ocnt == 4) win = 1;
		}
			// col action
		for(i = 0; i < 4; i++){
			Xcnt = Ocnt = 0;
			for(j = 0; j < 4; j++){
				if(board[j][i] == 'X') Xcnt++;
				if(board[j][i] == 'O') Ocnt++;
			}
			if(Xcnt == 4) win = 0;
			if(Ocnt == 4) win = 1;
		}

			// dig1 action
		Xcnt = Ocnt = 0;
		for(i = 0; i < 4; i++){
			if(board[i][i] == 'X') Xcnt++;
			if(board[i][i] == 'O') Ocnt++;
		}
		if(Xcnt == 4) win = 0;
		if(Ocnt == 4) win = 1;
			
			// dig2 action
		Xcnt = Ocnt = 0;
		for(i = 0; i < 4; i++){
			if(board[3 - i][i] == 'X') Xcnt++;
			if(board[3 - i][i] == 'O') Ocnt++;
		}
		if(Xcnt == 4) win = 0;
		if(Ocnt == 4) win = 1;

		// second: T = O
		
		if(T_x != -1)
			board[T_x][T_y] = 'O';

			// row action
		for(i = 0; i < 4; i++){
			Xcnt = Ocnt = 0;
			for(j = 0; j < 4; j++){
				if(board[i][j] == 'X') Xcnt++;
				if(board[i][j] == 'O') Ocnt++;
			}
			if(Xcnt == 4) win = 0;
			if(Ocnt == 4) win = 1;
		}
			// col action
		for(i = 0; i < 4; i++){
			Xcnt = Ocnt = 0;
			for(j = 0; j < 4; j++){
				if(board[j][i] == 'X') Xcnt++;
				if(board[j][i] == 'O') Ocnt++;
			}
			if(Xcnt == 4) win = 0;
			if(Ocnt == 4) win = 1;
		}

			// dig1 action
		Xcnt = Ocnt = 0;
		for(i = 0; i < 4; i++){
			if(board[i][i] == 'X') Xcnt++;
			if(board[i][i] == 'O') Ocnt++;
		}
		if(Xcnt == 4) win = 0;
		if(Ocnt == 4) win = 1;
			
			// dig2 action
		Xcnt = Ocnt = 0;
		for(i = 0; i < 4; i++){
			if(board[3 - i][i] == 'X') Xcnt++;
			if(board[3 - i][i] == 'O') Ocnt++;
		}
		if(Xcnt == 4) win = 0;
		if(Ocnt == 4) win = 1;


		cout << "Case #" << ++t << ": ";
		if(win == 0)
			cout << "X won";
		if(win == 1)
			cout << "O won";
		if(win == 2 && incomplete)
			cout << "Game has not completed";
		if(win == 2 && !incomplete)
			cout << "Draw";
		cout << endl;
		
	}

	
	return 0;
}

