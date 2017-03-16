#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string check_line(char board[4][4], char player, int y, int x, int dy, int dx){
	if (player == 'T'){
		if (check_line(board, 'X', y, x, dy, dx) == "X")
			return "X";
		return check_line(board, 'O', y, x, dy, dx);
	}
	int count; string ans = "";
	ans += player;
	for (count = 0; y >= 0 && y < 4 && x >= 0 && x < 4 && (board[y][x] == player || board[y][x] == 'T'); y += dy, x += dx, ++count);
	return (count==4 ? ans : ".");
}

string check_board(char board[4][4]){
	string ans;
	for (int y = 0; y < 4; ++y)
		if ((ans = check_line(board, board[y][0], y, 0, 0, 1)) != ".")
			return ans + " won";
	for (int x = 0; x < 4; ++x)
		if ((ans = check_line(board, board[0][x], 0, x, 1, 0)) != ".")
			return ans + " won";
	if ((ans = check_line(board, board[0][0], 0, 0, 1, 1)) != ".")
		return ans + " won";
	if ((ans = check_line(board, board[0][3], 0, 3, 1, -1)) != ".")
		return ans + " won";
	for (int y = 0; y < 4; ++y)
		for (int x = 0; x < 4; ++x)
			if (board[y][x] == '.')
				return "Game has not completed";
	return "Draw";
}

int main(){
	freopen("tomek.in", "r", stdin);
	freopen("tomek.out", "w", stdout);
	int run; char board[4][4]; string line;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		getline(cin, line);
		for (int y = 0; y < 4; ++y){
			getline(cin, line);
			for (int x = 0; x < 4; ++x) board[y][x] = line[x];
		}
		cout << "Case #" << a << ": " << check_board(board) << endl;
	}
	return 0;
}
