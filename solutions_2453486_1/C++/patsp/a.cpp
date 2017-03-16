#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <complex>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,start,end) for (int var=(start); var<=(end); ++var)
#define FORD(var,start,end) for (int var=(start); var>=(end); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

// typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector< vector<int> > VVI;
typedef vector< vector<bool> > VVB;

static char board[4][4];

int main() {
    int nTests = 0;
    cin >> nTests;

    FOR (test, 1, nTests) {

        REP (i, 4) REP (j, 4) {
            cin >> board[i][j];
        }

        bool wonX = false; bool wonO = false;
        int nEmpty = 0;
        REP (i, 4) REP (j, 4) {
            if (board[i][j] == '.') ++nEmpty;
            FOR (dy, -1, 1) FOR (dx, -1, 1) if (!(dx == 0 && dy == 0)) {
                int nX = 0; int nO = 0; int nT = 0;
                FOR (k, 0, 3) {
                    int newI = i+k*dy; int newJ = j+k*dx;
                    if (0 <= newI && newI < 4 && 0 <= newJ && newJ < 4) {
                        if (board[newI][newJ] == 'X') ++nX;
                        else if (board[newI][newJ] == 'O') ++nO;
                        else if (board[newI][newJ] == 'T') ++nT;
                    }
                }
                if (nX == 4 || (nX == 3 && nT == 1)) {
                    wonX = true;
                } else if (nO == 4 || (nO == 3 && nT == 1)) {
                    wonO = true;
                }
            }
        }

        cout << "Case #" << test << ": ";
        if (wonX) cout << "X won\n";
        else if (wonO) cout << "O won\n";
        else if (nEmpty == 0) cout << "Draw\n";
        else cout << "Game has not completed\n";
    }

    return 0;
}
