#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>

#define EPS (1e-9) 
#define PI (2 * acos(0.0)) 
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) ) 
#define REP(x,n)  for(int x=0;x<(int)(n);x++) 
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++) 
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x) 
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr) 
#define ALL(X)    (X).begin(),(X).end() 
#define mem0(X)    memset((X),0,sizeof(X)) 
#define mem1(X)    memset((X),255,sizeof(X)) 

typedef long long LL;

template<class T> inline T & max(T&a, T&b) {
    return a > b ? a : b;
}
using namespace std;

string dostuff() {
    string board[4];
    REP(i, 4) cin >> board[i];
    int O = 0, X = 0, tempO = 0, tempX = 0, none = 0;

    REP(i, 4) {
        if (board[i][i] == 'X')X++;
        if (board[i][i] == 'O')O++;
        if (board[i][i] == 'T') X++, O++;
    }

    REP(i, 4) {
        if (board[i][3 - i] == 'X') tempX++;
        if (board[i][3 - i] == 'O') tempO++;
        if (board[i][3 - i] == 'T')tempX++, tempO++;
    }
    X = max(X, tempX), O = max(O, tempO);
    REP(i, 4)REP(j, 4) if (board[i][j] == '.') none++;

    REP(i, 4) {
        tempX = 0, tempO = 0;

        REP(j, 4) {
            if (board[i][j] == 'X')tempX++;
            if (board[i][j] == 'O')tempO++;
            if (board[i][j] == 'T') tempX++, tempO++;
        }
        X = max(X, tempX), O = max(O, tempO), tempX = 0, tempO = 0;

        tempX = 0, tempO = 0;

        REP(j, 4) {
            if (board[j][i] == 'X')tempX++;
            if (board[j][i] == 'O')tempO++;
            if (board[j][i] == 'T') tempX++, tempO++;
        }
        X = max(X, tempX), O = max(O, tempO);
    }
    if (X == 4) return"X won";
    if (O == 4) return "O won";
    if (none)return "Game has not completed";
    return "Draw";
}

int main(int argc, char** argv) {
    int T;
    cin >> T;

    REP(t, T) {
        cout << "Case #" << t + 1 << ": " << dostuff() << endl;
    }
    return 0;
}

