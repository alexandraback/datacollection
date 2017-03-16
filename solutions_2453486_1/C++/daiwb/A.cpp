#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string mat[4];

bool isok(char ch) {
    REP(i,4) {
        bool flag = true;
        REP(j,4) {
            if (mat[i][j] != ch && mat[i][j] != 'T') {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }

    REP(j,4) {
        bool flag = true;
        REP(i,4) {
            if (mat[i][j] != ch && mat[i][j] != 'T') {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }

    bool flag = true;
    REP(i,4) {
        if (mat[i][i] != ch && mat[i][i] != 'T') {
            flag = false;
            break;
        }
    }
    
    if (flag) return true;

    flag = true;
    REP(i,4) {
        if (mat[i][3 - i] != ch && mat[i][3 - i] != 'T') {
            flag = false;
            break;
        }
    }
    
    if (flag) return true;
    
    return false;
}

void run() {
    REP(i,4) cin >> mat[i];

    if (isok('X')) {
        cout << "X won" << endl;
        return;
    }

    if (isok('O')) {
        cout << "O won" << endl;
        return;
    }

    REP(i,4) REP(j,4) if (mat[i][j] == '.') {
        cout << "Game has not completed" << endl;
        return;
    }

    cout << "Draw" << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
