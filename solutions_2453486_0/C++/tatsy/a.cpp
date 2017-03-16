#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <complex>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;
vector<string> board;

int solve() {
    char c;
    bool ok;

    // check vertical lines
    rep(j,4) {
        c = board[0][j];
        if(c == '.') continue;
        ok = true;
        repa(i,1,3) {
            if(board[i][j] != 'T' && c != board[i][j]) {
                ok = false;
                break;
            }
        }
        if(ok) return c;
    }

    // check horizontal lines
    rep(i,4) {
        c = board[i][0];
        if(c == '.') continue;
        ok = true;
        repa(j,1,3) {
            if(board[i][j] != 'T' && c != board[i][j]) {
                ok = false;
                break;
            }
        }
        if(ok) return c;
    }

    // check diagonal lines
    c = board[0][0];
    if(c != '.') {
        ok = true;
        repa(i,1,3) {
            if(board[i][i] != 'T' && c != board[i][i]) {
                ok = false;
                break;
            }
        }
        if(ok) return c;
    }

    c = board[0][3];
    if(c != '.') {
        ok = true;
        repa(i,1,3) {
            if(board[i][3-i] != 'T' && c != board[i][3-i]) {
                ok = false;
                break;
            }
        }
        if(ok) return c;
    }

    // check if there exist empty cells
    rep(i,4) {
        rep(j,4) {
            if(board[i][j] == '.') return 1;
        }
    }

    return 0;
}

int main() {
    cin >> T;
    rep(t, T) {
        board = vector<string>(4);
        rep(k,4) cin >> board[k];

        printf("Case #%d: ", t+1);
        switch(solve()) {
        case 'X':
            cout << "X won" << endl;
            break;

        case 'O':
            cout << "O won" << endl;
            break;

        case 0:
            cout << "Draw" << endl;
            break;

        case 1:
            cout << "Game has not completed" << endl;
            break;
        }
    }
}
