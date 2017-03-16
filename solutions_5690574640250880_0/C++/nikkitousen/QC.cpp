#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back

int r, c, m;
int board[51][51];
int val[51][51];

bool bt(int i, int h, int rem) {
    if(i >= r) return false;
    for(int l=h; l>=0; l--) {
        if(l == 1) continue;
        if(i == 0) {
            if(2*l > rem) continue;
            if(2*l == rem or bt(i+2, l, rem-2*l)) {
                REP(k, l) board[i][k] = 0, board[i+1][k] = 0;
                return true;
            }
        } else {
            if(l == rem or bt(i+1, l, rem-l)) {
                REP(k, l) board[i][k] = 0;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int T;
    cin >> T;
    REP(caso, T) {
        cin >> r >> c >> m;
        REP(i, r) REP(j, c) board[i][j] = 1;
        
        if(r == 1) {
            REP(i, c-m) board[0][i] = 0;
        } else if (c == 1) {
            REP(i, r-m) board[i][0] = 0;
        }
        
        bool ret = bt(0, c, r*c-m);
        
        // REP(i, r) {
        //     REP(j, c) cout << board[i][j];
        //     cout << endl;
        // }
        
        cout << "Case #" << caso+1 << ":\n";
        if(r*c-m == 1 or r == 1 or c == 1 or ret) {
            REP(i, r) {
                REP(j, c) {
                    if(i == 0 and j == 0) cout << "c";
                    else if(board[i][j] == 0) cout << ".";
                    else cout << "*";
                }
                cout << endl;
            }
        } else cout << "Impossible\n";
    }
}
