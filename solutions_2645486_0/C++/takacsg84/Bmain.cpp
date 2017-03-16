#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>
#include <numeric>
#include <limits.h>
#include <limits>
#include <iterator>
#include <iomanip>
#include <bitset>
#include <assert.h>

using namespace std;

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

typedef long long LL;
#define MAXE 7
#define MAXN 13

int doStuffSmall() {
    int E, R, N, x, result = 0;
    cin >> E >> R >> N;
    int DP[MAXN][MAXE];
    REP(i, MAXN)REP(j, MAXE)DP[i][j] = -1;
    DP[0][E] = 0;

    REP(i, N) {
        cin >> x;
        REP(e, MAXE)if (DP[i][e] >= 0)REP(e2, e + 1) {
            int E2 = min(E, e - e2 + R), &next = DP[i + 1][E2];
            next = max(next, DP[i][e] + x * e2);
        }
    }
    REP(i, MAXE) result = max(DP[N][i], result);
    return result;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    REP(t, T) cout << "Case #" << t + 1 << ": " << doStuffSmall() << endl;
    cout.flush();
    return 0;
}