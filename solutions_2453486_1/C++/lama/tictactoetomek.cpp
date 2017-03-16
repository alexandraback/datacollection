#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int T;
char board[6][6];

bool win(char player) {
    int res = 0;
    // diagonal
    for(int i = 0; i < 4; i++) {
        if(board[i][i] == player || board[i][i] == 'T') res++;
        else break;
    }
    if(res == 4) return true;
    res = 0;
    for(int i = 0; i < 4; i++) {
        if(board[3 - i][i] == player || board[3 - i][i] == 'T') res++;
        else break;
    }
    if(res == 4) return true;

    // horizontal & vertical
    for(int i = 0; i < 4; i++) {
        res = 0;
        for(int j = 0; j < 4; j++) {
            if(board[i][j] == player || board[i][j] == 'T') res++;
            else break;
        }
        if(res == 4) return true;
    }
    for(int j = 0; j < 4; j++) {
        res = 0;
        for(int i = 0; i < 4; i++) {
            if(board[i][j] == player || board[i][j] == 'T') res++;
            else break;
        }
        if(res == 4) return true;
    }
    return false;
}

int main() {
    cin >> T;
    for(int Ti = 1; Ti <= T; Ti++) {
        bool full = true;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> board[i][j];
                if(board[i][j] == '.') full = false;
            }
        }

        cout << "Case #" << Ti << ": ";
        if(win('X')) cout << "X won" << endl;
        else if(win('O')) cout << "O won" << endl;
        else if(full) cout << "Draw" << endl;
        else cout << "Game has not completed" << endl;
    }
    return 0;
}