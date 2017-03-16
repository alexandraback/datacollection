#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <string>
#include <utility>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include <stdio.h>
#include <cstring>

#include <stdlib.h>
#include <time.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef unsigned char UC;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<UI> VUI;

#define DEBUG 1
#define F(i,n) for(int i=0;i<n;i++)
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define FORE(i,s,n) for(int i=s;i<=n;i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-1*(a)) : (a))
#define INSET(s, e) ((s).find(e) != (s).end())
#define INMAP(s, e) ((s).find(e) != (s).end())
#define TRACE(v) (cout << "TRACE(" << #v << "): " << v << endl)
#define TRACE1D(v,s) { cout << "TRACE1D(" << #v << ", " << (s) << "): "; F(i,s) cout << (v)[i] << " "; cout << endl; }
#define TRACE2D(v,s1,s2) { cout << "TRACE2D(" << #v << ", " << (s1) << ", " << (s2) << "): "; F(i,s1) { cout << endl << "\t"; F(j,s2) cout << v[i][j] << " "; } cout << endl; }
#define TRACE2DS(v) { cout << "TRACE2DS(" << #v << "): "; F(i,v.size()) { cout << endl << "\t"; F(j,v[i].size()) cout << v[i][j] << " "; } cout << endl; }
#define FOREACH(it, s) for (auto it = s.begin(); it != s.end(); it++)

#define XWON 0
#define OWON 1
#define DRAW 2
#define NOT_OVER 3

UC lineStatus(const string &line) {
    static char C[128];
    C['.'] = C['O'] = C['T'] = C['X'] = 0;

    F(i,4) {
        C[line[i]]++;
    }

    if (C['.'] > 0) {
        return NOT_OVER;
    } else if (C['X'] > 0 && C['O'] > 0) {
        return DRAW;
    } else if (C['X'] > 0) {
        return XWON;
    } else {
        return OWON;
    }
}

UC getGameStatus(const vector<string> &board) {
    UC statuses[4];
    memset(statuses, 0, sizeof statuses);

    // rows
    F(r,4) {
        statuses[lineStatus(board[r])]++;
    }

    // cols
    F(c,4) {
        string data = "";
        FOR(i,0,4) {
            data.push_back(board[i][c]);
        }
        statuses[lineStatus(data)]++;
    }

    // diagonals
    string data1 = "", data2 = "";
    F(i,4) {
        data1.push_back(board[i][i]);
        data2.push_back(board[i][3 - i]);
    }
    statuses[lineStatus(data1)]++;
    statuses[lineStatus(data2)]++;

    UC status;
    if (statuses[XWON]) {
        status = XWON;
    } else if (statuses[OWON]) {
        status = OWON;
    } else if (statuses[NOT_OVER]) {
        status = NOT_OVER;
    } else {
        status = DRAW;
    }

    return status;
}

void solve(char *in, char *out) {
    if (in != NULL) {
        freopen(in, "r", stdin);
    }

    if (out != NULL) {
        freopen(out, "w", stdout);
    }

    UI t;
    cin >> t;
    FOR(i,1,t + 1) {
        vector<string> board;
        board.resize(4);
        F(j,4) {
            cin >> board[j];
        }

        UC status = getGameStatus(board);
        cout << "Case #" << i << ": ";
        switch (status) {
            case XWON: cout << "X won"; break;
            case OWON: cout << "O won"; break;
            case DRAW: cout << "Draw"; break;
            case NOT_OVER: cout << "Game has not completed"; break;
        }
        cout << endl;
    }
}

void assert(bool b, const char *msg = NULL) {
    static int test = 0;
    test++;

    if (!b) {
        if (msg == NULL) {
            cout << "Error :: " << test << endl;
        } else {
            cout << "Error :: " << test << " :: " << msg << endl;
        }
    }
}

void tests() {

}

int main(int argc, char **argv) {
    //srand(time(NULL));
    char *in, *out;
    if (argc == 3) {
        in = argv[1];
        out = argv[2];
    } else {
        in = NULL;
        out = NULL;
    }

    tests();
    solve(in, out);
    return 0;
}
