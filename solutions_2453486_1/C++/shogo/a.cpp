#include <iostream>

using namespace std;

bool winrow(string s[4], int row, char p) {
    for(int i = 0; i < 4; i++) {
        if(s[row][i] != p && s[row][i] != 'T') return false;
    }
    return true;
}

bool wincolumn(string s[4], int column, char p) {
    for(int i = 0; i < 4; i++) {
        if(s[i][column] != p && s[i][column] != 'T') return false;
    }
    return true;
}

bool windiag1(string s[4], char p) {
    for(int i = 0; i < 4; i++) {
        if(s[i][i] != p && s[i][i] != 'T') return false;
    }
    return true;
}

bool windiag2(string s[4], char p) {
    for(int i = 0; i < 4; i++) {
        if(s[i][3-i] != p && s[i][3-i] != 'T') return false;
    }
    return true;
}

bool win(string s[4], char p) {
    for(int i = 0; i < 4; i++) {
        if(winrow(s, i, p)) return true;
        if(wincolumn(s, i, p)) return true;
    }
    if(windiag1(s, p)) return true;
    if(windiag2(s, p)) return true;
    return false;
}

bool over(string s[4]) {
    for(int i=0; i < 4; i++) {
        for(int j=0; j < 4; j++) {
            if(s[i][j] == '.') return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    for(int no = 1; no <= N; no++) {
        string board[4];
        for(int i=0; i<4;i++) cin >> board[i];
        if(win(board, 'X')) cout << "Case #" << no << ": X won" << endl;
        else if(win(board, 'O')) cout << "Case #" << no << ": O won" << endl;
        else if(over(board)) cout << "Case #" << no << ": Draw" << endl;
        else cout << "Case #" << no << ": Game has not completed" << endl;
    }
}
