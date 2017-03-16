#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;

// Ok, it's not nice as can be and code is dublicated
// many times. But nodody gives a shit, I wrote it in
// 5 minutes and submit :)

string g[4];

void solveCase(int tc) {
    string res;
    rep(i, 4) {
        cin >> g[i];
        if (l(g[i]) != 4)
            throw 1;
    }
    bool empty = false;
    int nX, nO;
    rep(i, 4) {
        nX = 0, nO = 0;
        rep(j, 4) {
            nX += (g[i][j] == 'X' || g[i][j] == 'T');
            nO += (g[i][j] == 'O' || g[i][j] == 'T');
            if (g[i][j] == '.') empty = true;
        }
        if (nX == 4) {
            res = "X won";
            goto nxt;
        } else if (nO == 4) {
            res = "O won";
            goto nxt;
        }
        nX = 0, nO = 0;
        rep(j, 4) {
            nX += (g[j][i] == 'X' || g[j][i] == 'T');
            nO += (g[j][i] == 'O' || g[j][i] == 'T');
        }
        if (nX == 4) {
            res = "X won";
            goto nxt;
        } else if (nO == 4) {
            res = "O won";
            goto nxt;
        }
    }
    nX = 0, nO = 0;
    rep(i, 4) {
        nX += (g[i][i] == 'X' || g[i][i] == 'T');
        nO += (g[i][i] == 'O' || g[i][i] == 'T');
    }
    if (nX == 4) {
        res = "X won";
        goto nxt;
    } else if (nO == 4) {
        res = "O won";
        goto nxt;
    }
    nX = 0, nO = 0;
    rep(i, 4) {
        nX += (g[i][4-i-1] == 'X' || g[i][4-i-1] == 'T');
        nO += (g[i][4-i-1] == 'O' || g[i][4-i-1] == 'T');
    }
    if (nX == 4) {
        res = "X won";
        goto nxt;
    } else if (nO == 4) {
        res = "O won";
        goto nxt;
    }
    if (!empty)
        res = "Draw";
    else
        res = "Game has not completed";
    nxt:;
    printf("Case #%d: %s\n", tc+1, res.c_str());
}

void solution()
{
    int tc;
    scanf("%d\n", &tc);
    rep(i, tc)
        solveCase(i);
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("A-small-attempt0.in", "rt", stdin);
   freopen("A-small-attempt0.out", "wt", stdout);
#endif
   solution();
#ifndef ONLINE_JUDGE
   fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
   return 0;
}
