#include <iostream>
#include <vector>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve() {
    vector<string> board(4);
    int symbols = 16;
    bool xwin = false, owin = false;
    rep(i,4) {
        cin >> board[i];
    }
    
    rep(i,4) {
        int t = 0, o = 0, x = 0;
        rep(j,4) {
            if (board[i][j] == 'X')x++;
            if (board[i][j] == 'O')o++;
            if (board[i][j] == 'T')t++;
            if (board[i][j] == '.')symbols--;
        }
        if (t + o == 4)owin = true;
        if (t + x == 4)xwin = true;
    }
    rep(i,4) {
        int t = 0, o = 0, x = 0;
        rep(j,4) {
            if (board[j][i] == 'X')x++;
            if (board[j][i] == 'O')o++;
            if (board[j][i] == 'T')t++;
        }
        if (t + o == 4)owin = true;
        if (t + x == 4)xwin = true;
    }
    {
        int t = 0, o = 0, x = 0;
        rep(j,4) {
            if (board[j][j] == 'X')x++;
            if (board[j][j] == 'O')o++;
            if (board[j][j] == 'T')t++;
        }
        if (t + o == 4)owin = true;
        if (t + x == 4)xwin = true;
    }
    {
        int t = 0, o = 0, x = 0;
        rep(j,4) {
            if (board[j][3-j] == 'X')x++;
            if (board[j][3-j] == 'O')o++;
            if (board[j][3-j] == 'T')t++;
        }
        if (t + o == 4)owin = true;
        if (t + x == 4)xwin = true;
    }
    if (owin) {
        cout << "O won" << endl;
    } else if (xwin) {
        cout << "X won" << endl;
    } else if (symbols == 16) {
        cout << "Draw" << endl;
    } else {
        cout << "Game has not completed" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    rep(i,T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
