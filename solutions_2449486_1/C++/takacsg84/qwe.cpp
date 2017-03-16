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
int X[100][100], N, M, all, best;
bool row[100], col[100], ok;

inline bool checkCol(const pair<int, int> &start, int v) {
    REP(i, N)if (!row[i] && X[i][start.second] != v) return false;
    return true;
}

inline bool checkRow(const pair<int, int> &start, int v) {
    REP(i, M) if (!col[i] && X[start.first][i] != v) return false;
    return true;
}

string dostuff() {
    mem0(X), mem0(row), mem0(col);
    cin >> N >> M, best = 101;
    REP(i, N)REP(j, M) cin >> X[i][j];
    while (best < 102) {
        pair<int, int> start;
        best = 102;
        REP(i, N)if (!row[i])REP(j, M)if (!col[j]) if (X[i][j] < best) best = X[i][j], start = pair<int, int>(i, j);
        if (checkCol(start, best))col[start.second] = true;
        else if (checkRow(start, best)) row[start.first] = true;
        else return "NO";
    }
    return "YES";
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    REP(t, T) cout << "Case #" << t + 1 << ": " << dostuff() << endl;
    return 0;
}

