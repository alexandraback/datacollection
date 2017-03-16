#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
char board[4][4];
int main(){
	int T;
	cin >> T;
	for(int curr_case = 1; curr_case <= T; ++curr_case){
		bool completed = true;
		for(int i = 0; i < 4; ++i){
			string s;
			cin >> s;
			for(int j = 0; j < 4; ++j){
				board[i][j]=s[j];
				if(s[j]=='.')
					completed = false;
			}
		}
		bool ready = false;
		cout << "Case #" << curr_case << ": ";
		int diag1Os = 0;
		int diag2Os = 0;
		bool diag1T = false;
		bool diag2T = false;
		for(int i = 0; i < 4; ++i){
			int horizontalOs = 0;
			int verticalOs = 0;
			bool horizontalT = false;
			bool verticalT = false;
			for(int j = 0; j < 4; ++j){
				if(board[i][j]=='O'){
					++horizontalOs;
				}else if(board[i][j]=='X'){
					--horizontalOs;
				}else if(board[i][j]=='T'){
					horizontalT = true;
				}
				if(board[j][i]=='O'){
					++verticalOs;
				}else if(board[j][i]=='X'){
					--verticalOs;
				}else if(board[j][i]=='T'){
					verticalT = true;
				}
			}
			if(horizontalOs == (horizontalT?3:4) || verticalOs == (verticalT?3:4)){
				ready = true;
				cout << "O won";
				break;
			}else if(horizontalOs == (horizontalT?-3:-4) || verticalOs == (verticalT?-3:-4)){
				ready = true;
				cout << "X won";
				break;
			}
			if(board[i][i]=='O'){
				++diag1Os;
			}else if(board[i][i]=='X'){
				--diag1Os;
			}else if(board[i][i] == 'T'){
				diag1T = true;
			}
			if(board[i][3-i] == 'O'){
				++diag2Os;
			}else if(board[i][3-i]=='X'){
				--diag2Os;
			}else if(board[i][3-i]=='T'){
				diag2T = true;
			}
		}
		if(!ready){
			if(diag1Os == (diag1T?3:4) || diag2Os == (diag2T?3:4)){
				cout << "O won";
			}else if(diag1Os == (diag1T?-3:-4) || diag2Os == (diag2T?-3:-4)){
				cout << "X won";
			}else{
				if(completed){
					cout << "Draw";
				}else{
					cout << "Game has not completed";
				}
			}
		}
		cout << endl;
		string s;
	}
    return 0;
}
