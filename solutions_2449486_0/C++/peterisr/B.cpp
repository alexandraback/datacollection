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
#include <initializer_list>

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

#define MAXN 111
#define MAXM 111

bool isPossibleLawn(UI n, UI m, UI L[MAXN][MAXM]) {
    int rowMax[MAXN], colMax[MAXM];
    F(r,n) {
        rowMax[r] = L[r][0];
        FOR(i,1,m) {
            rowMax[r] = MAX(rowMax[r], L[r][i]);
        }
    }

    F(c,m) {
        colMax[c] = L[0][c];
        FOR(i,1,n) {
            colMax[c] = MAX(colMax[c], L[i][c]);
        }
    }

    if (false) {
        TRACE2D(L, n, m);
        TRACE1D(rowMax, n);
        TRACE1D(colMax, m);
    }

    F(r,n) {
        F(c,m) {
            UC e = L[r][c];
            if (e < rowMax[r] && e < colMax[c]) {
                return false;
            }
        }
    }

    return true;
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
        UI n, m;
        cin >> n >> m;

        UI L[MAXN][MAXM];
        F(r,n) {
            F(c,m) {
                cin >> L[r][c];
            }
        }

        cout << "Case #" << i << ": " << (isPossibleLawn(n, m, L) ? "YES" : "NO") << endl;
    }
}

void assert(initializer_list< initializer_list<UI> > lawn, bool expect, const char *msg = NULL) {
    static int test = 0;
    test++;

    UI L[MAXN][MAXM], r = 0, c;
    FOREACH(iter, lawn) {
        c = 0;
        FOREACH(iter2, (*iter)) {
            L[r][c++] = *iter2;
        }
        r++;
    }

    bool got = isPossibleLawn(r, c, L);
    if (got != expect) {
        if (msg == NULL) {
            cout << "Error :: " << test << endl;
        } else {
            cout << "Error :: " << test << " :: " << msg << endl;
        }
    }
}

void tests() {
    // 1
    assert({{1}}, true);
    assert({{1,1}}, true);
    assert({{1,2}}, true);
    assert({{2,1}}, true);

    // 5
    assert({{1,1,1}}, true);
    assert({{1,2,1}}, true);
    assert({{2,1,2}}, true);
    assert({{2,1,1}}, true);
    assert({{2,2,1}}, true);

    // 10
    assert({{2,2,1,2,5,8,9}}, true);
    assert({
        {1},
        {1},
    }, true);
    assert({
        {1},
        {2},
    }, true);
    assert({
        {2},
        {2},
    }, true);
    assert({
        {2,2},
        {2,2},
    }, true);

    // 15
    assert({
        {2,1},
        {2,1},
    }, true);
    assert({
        {1,1},
        {2,2},
    }, true);
    assert({
        {2,1},
        {2,2},
    }, false);
    assert({
        {2,1},
        {1,2},
    }, false);
    assert({
        {1,1},
        {1,2},
    }, true);

    // 20
    assert({
        {1,1,2},
        {1,1,2},
    }, true);
    assert({
        {1,1,2},
        {1,1,1},
    }, true);
    assert({
        {2,2,1},
        {2,2,2},
    }, false);
    assert({
        {2,1,2},
        {2,1,2},
    }, true);
    assert({
        {3,1,2},
        {2,1,2},
    }, true);

    // 25
    assert({
        {3,1,2},
        {2,1,3},
    }, false);
    assert({
        {3,2,2},
        {2,2,3},
    }, false);
    assert({
        {3,3,3},
        {3,1,3},
    }, false);
    assert({
        {1,2,3},
        {1,2,3},
        {1,2,3},
    }, true);
    assert({
        {1,2,3},
        {2,2,3},
        {1,2,3},
    }, false);

    // 30: pub tests
    assert({
        {2,1,2},
        {1,1,1},
        {2,1,2}
    }, true);
    assert({
        {2,2,2,2,2},
        {2,1,1,1,2},
        {2,1,2,1,2},
        {2,1,1,1,2},
        {2,2,2,2,2},
    }, false);
    assert({
        {1,2,1},
    }, true);
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

