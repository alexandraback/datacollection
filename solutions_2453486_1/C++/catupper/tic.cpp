#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int t;
string board[4];

bool search(char x){
    for(int i = 0;i < 4;i++){
	bool raw = true, column = true;
	for(int j = 0;j < 4;j++){
	    if(board[i][j] != x && board[i][j] != 'T')
		raw = false;
	    if(board[j][i] != x && board[j][i] != 'T')
		column = false;
	}
	if(raw || column)
	    return true;
    }
    bool l = true, r = true;
    for(int i = 0;i < 4;i++){
	if(board[i][i] != x && board[i][i] != 'T')
	    l = false;
	if(board[i][3 - i] != x && board[i][3 - i] != 'T')
	    r = false;
    }
    if(l || r)
	return true;
    return false;
}

int main(){
    cin >> t;
    for(int i = 1;i <= t;i++){
	bool end = true;
	for(int j = 0;j < 4;j++){
	    cin >> board[j];
	    for(int k = 0;k < 4;k++){
		if(board[j][k] == '.')
		    end = false;
	    }
	}
	
	if(search('O'))
	    cout << "Case #" << i << ": " << "O won" << endl;

	else if(search('X'))
	    cout << "Case #" << i << ": " << "X won" << endl;
	
	else if(end)
	    cout << "Case #" << i << ": " << "Draw" << endl;
	else
	    cout << "Case #" << i << ": " << "Game has not completed" << endl;
    }
    return 0;
}
