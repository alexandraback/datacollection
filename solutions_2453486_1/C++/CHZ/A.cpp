#include<iostream>
#include<cstdio>

using namespace std;
int test_win(int board[4][4]) {
    int result = 0;
/*    for (int i = 0 ; i < 4; ++i) {
	for (int j = 0 ; j < 4; ++j) {
	    cout << board[i][j];
	}
	cout << endl;
    }
	cout << endl;*/
    for (int i = 0 ; i < 4; ++i) {
	if (board[i][0] + board[i][1] + board[i][2] + board[i][3] == 4)
	    result = 1;
	if (board[0][i] + board[1][i] + board[2][i] + board[3][i] == 4)
	    result = 1;
    }
    if (board[0][0] + board[1][1] + board[2][2] + board[3][3] == 4)
	result = 1;
    if (board[0][3] + board[1][2] + board[2][1] + board[3][0] == 4)
	result = 1;
    return result;
}
int main(int artc, char* argv[]) {

    int TIME;// number of test
    char output[4][30]= { "X won", "O won", "Draw", "Game has not completed" };
    cin >> TIME;
    int board[2][4][4];
    char tmp_char;
    int num_empty;
    int answer;
    for (int t = 0 ; t < TIME; t++) {
	num_empty = 0;
	for (int i = 0 ; i < 4; ++i) {
	    for (int j = 0 ; j < 4; ++j) {
		cin >> tmp_char;
		if (tmp_char=='X') {
		    board[0][i][j] = 1;
		    board[1][i][j] = 0;
		}
		else if (tmp_char == 'O') {
		    board[0][i][j] = 0;
		    board[1][i][j] = 1;
		}
		else if (tmp_char == 'T') {
		    board[0][i][j] = 1;
		    board[1][i][j] = 1;
		}
		else if (tmp_char == '.') {
		    board[0][i][j] = 0;
		    board[1][i][j] = 0;
		    num_empty++;
		}
	    }
	}
	if (test_win(board[0]) == 1) {
	    answer = 0;
	}
	else if (test_win(board[1]) == 1) {
	    answer = 1;
	}
	else if (num_empty == 0) {
	    answer = 2;
	}
	else {
	    answer = 3;
	}
	//output
	printf("Case #%d: %s\n",t+1, output[answer]);
    }
    return 0;
}
