#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
#define SZ(a) ((int)a.size())
using namespace std;

const double PI = 2.0 * acos (0.0);

typedef pair <int, int> PII;

template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

char res[100][100];

void fillArr(int x1, int y1, int x2, int y2, char c) {
    FOR(i, x1, x2) FOR(j, y1, y2) res[i][j] = c;
}
void fillArr(int x, int y, char c) {
    res[x][y] = c;
}

void printOut(int R, int C) {
    fillArr(1, 1, 'c');
    FOR(i, 1, R) {
        FOR(j, 1, C) cout << res[i][j];
        cout << endl;
    }
}

void equal1(int R, int C, int M) {
    fillArr(1, 1, R, C, '*');
    if (R == 1) fillArr(1, 1, 1, C - M, '.');
    else fillArr(1, 1, R - M, 1, '.');
    printOut(R, C);
}

void equal2(int R, int C, int M) {
    if (R * C - M == 2) {
        cout << "Impossible" << endl;
        return;
    }
    fillArr(1, 1, R, C, '*');
    if (R * C - M == 1) {
        printOut(R, C);
        return;
    }
    if (M % 2) {
        cout << "Impossible" << endl;
        return;
    }
    fillArr(1, 1, R, C, '*');
    if (C == 2) {
        fillArr(1, 1, (R * C - M)/2, 2, '.');
        printOut(R, C);
    } else {
        fillArr(1, 1, 2, (R * C - M)/2, '.');
        printOut(R, C);
    }
}


void process(int R, int C, int M) {
    fillArr(1, 1, R, C, '*');
    int remain = R * C - M;
    if (remain == 1) {
        printOut(R, C);
        return;
    }
    if (remain == 2 || remain == 3 || remain == 5 || remain == 7) {
        cout << "Impossible" << endl;
        return;
    }
    if (remain == 4) {
        fillArr(1, 1, 2, 2, '.');
        printOut(R, C);
        return;
    }
    if (remain == 6) {
        fillArr(1, 1, 2, 3, '.');
        printOut(R, C);
        return;
    }

    if (remain > R * 3) {
        int div = remain / R;
        fillArr(1, 1, R, div, '.');
        int mod = remain % R;
        if (mod == 1) {
            fillArr(R, div, '*');
            fillArr(1, div + 1, 2, div + 1, '.');
        } else fillArr(1, div + 1, mod, div + 1, '.');
    } else {
        int div = remain/3;
        int mod = remain%3;
        fillArr(1, 1, div, 3, '.');
        if (mod == 1) {
            fillArr(div, 3, '*');
            fillArr(div + 1, 1, div + 1, 2, '.');
        } else fillArr(div + 1, 1, div + 1, mod, '.');
    }
    printOut(R, C);
}

int main() {
    freopen("C-large.in","r",stdin);
    freopen("c-large.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        int R, C, M;
        cout << "Case #" << test << ":" << endl;
        cin >> R >> C >> M;
        if (min(R, C) == 1) {
            equal1(R, C, M);
            continue;
        }
        if (min(R, C) == 2) {
            equal2(R, C, M);
            continue;
        }
        process(R, C, M);
    }
    return 0;
}
