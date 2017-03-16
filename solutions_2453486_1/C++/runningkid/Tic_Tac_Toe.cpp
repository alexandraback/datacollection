#include <iostream>
using namespace std;

int T;
char board[4][4];


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> T;
	for(int icase = 1; icase <= T; icase++){
		cout << "Case #"<< icase << ": ";
		for(int row = 0; row < 4; row++){
			for(int col = 0; col < 4; col++){
				cin >> board[row][col];
			}
		}
		bool flag = false;
		int dot_num = 0;
		// row
		for(int i = 0 ; i < 4; i++){
			int x_num = 0;
			int o_num = 0;
			int t_num = 0;
			for(int j = 0; j < 4; j++){
				if(board[i][j] == 'X') x_num++;
				if(board[i][j] == 'O') o_num++;
				if(board[i][j] == 'T') t_num++;
				if(board[i][j] == '.') dot_num++;
			}
			if(x_num + t_num == 4){
				cout << "X won" << endl;
				flag = true;
				break;
			}
			if(o_num + t_num == 4){
				cout << "O won" << endl;
				flag = true;
				break;
			}
		}
		
		if(flag) continue;
		//coloum
		for(int i = 0; i < 4; i++){
			int x_num = 0;
			int o_num = 0;
			int t_num = 0;
			for(int j = 0; j < 4; j++){
				if(board[j][i] == 'X') x_num++;
				if(board[j][i] == 'O') o_num++;
				if(board[j][i] == 'T') t_num++;
				if(board[j][i] == '.') dot_num++;
			}
			if(x_num + t_num == 4){
				cout << "X won" << endl;
				flag = true;
				break;
			}
			if(o_num + t_num == 4){
				cout << "O won" << endl;
				flag = true;
				break;
			}
		}
	
		if(flag) continue;
		//diagonal		
		int x_num = 0;
		int o_num = 0;
		int t_num = 0;
		for(int i = 0; i < 4; i++){
			if(board[i][i] == 'X') x_num++;
			if(board[i][i] == 'O') o_num++;
			if(board[i][i] == 'T') t_num++;
			if(board[i][i] == '.') dot_num++;
		}
		if(x_num + t_num == 4){
			cout << "X won" << endl;
			flag = true;
		}
		if(o_num + t_num == 4){
			cout << "O won" << endl;
			flag = true;
		}
		if(flag) continue;

		x_num = 0;
		o_num = 0;
		t_num = 0;
		for(int i = 0; i < 4; i++){
			if(board[i][3-i] == 'X') x_num++;
			if(board[i][3-i] == 'O') o_num++;
			if(board[i][3-i] == 'T') t_num++;
			if(board[i][3-i] == '.') dot_num++;
		}
		if(x_num + t_num == 4){
			cout << "X won" << endl;
			flag = true;
		}
		if(o_num + t_num == 4){
			cout << "O won" << endl;
			flag = true;
		}
		if(flag) continue;

		if(dot_num == 0)
			cout << "Draw" << endl;
		else cout << "Game has not completed" << endl;
	}
	return 0;
}