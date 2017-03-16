/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: C.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2014-04-12
 */
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,s,t) for (LL i = (s); i <= (t); ++i)
#define FOREACH(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;
typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

const double pi = acos(-1);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 50 + 5;

char g[maxn][maxn];

void calc(int r, int c, int m)
{
        int k = r * c - m;
        if (m == 0) {
                REP(i,r) REP(j,c) g[i][j] = '.';
                g[0][0] = 'c';
                REP(i,r) {
                        REP(j,c) cout << g[i][j];
                        cout << endl;
                }
                return;
        }
        if (k == 1) {
                REP(i,r) REP(j,c) g[i][j] = '*';
                g[0][0] = 'c';
                REP(i,r) {
                        REP(j,c) cout << g[i][j];
                        cout << endl;
                }
                return;
        }
        if (r == 1) {
                REP(j,c) {
                        if (j < m) cout << '*';
                        else if (j < c - 1) cout << '.';
                        else  cout << 'c';
                }
                cout << endl;
                return;
        }
        if (c == 1) {
                REP(i,r) {
                        if (i < m) cout << '*' << endl;
                        else if (i < r - 1) cout << '.' << endl;
                        else cout << 'c' << endl;
                }
                return;
        }
        if (r == 2) {
                if (m != r * c - 1 && m % 2 != 0) {
                        cout << "Impossible" << endl;
                        return;
                }
                if (c - m / 2 == 1) {
                        cout << "Impossible" << endl;
                        return;
                }
                REP(j,c) {
                        if (j < m / 2) cout << '*';
                        else if (j < c - 1) cout << '.';
                        else if (m == r * c - 1) cout << '*';
                        else cout << '.';
                }
                cout << endl;
                REP(j,c) {
                        if (j < m / 2) cout << '*';
                        else if (j < c - 1) cout << '.';
                        else cout << 'c';
                }
                cout << endl;
                return;
        }
        if (c == 2) {
                if (m != r * c - 1 && m % 2 != 0) {
                        cout << "Impossible" << endl;
                        return;
                }
                if (r - m / 2 == 1) {
                        cout << "Impossible" << endl;
                        return;
                }
                REP(i,r) {
                        if (i < m / 2) cout << "**" << endl;
                        else if (i < r - 1) cout << ".." << endl;
                        else if (m == r * c - 1) cout << "*c" << endl;
                        else cout << ".c" << endl;
                }
                return;
        }
        REP(i,r) REP(j,c) g[i][j] = '*';
        REP(x,r) if (x != 1) {
                FOR(y,max(x+1,2),r) if ((k - x) % y == 0 &&
                                (k - x) / y > 1 && (k - x) / y < c) {
                        REP(i,y) REP(j,(k-x)/y) g[i][j] = '.';
                        REP(i,x) g[i][(k-x)/y] = '.';
                        g[0][0] = 'c';
                        REP(i,r) {
                                REP(j,c) cout << g[i][j];
                                cout << endl;
                        }
                        return;
                }
        }
        REP(x,c) if (x != 1) {
                FOR(y,max(x+1,2),c) if ((k - x) % y == 0 &&
                                (k - x) / y > 1 && (k - x) / y < r) {
                        REP(i,(k-x)/y) REP(j,y) g[i][j] = '.';
                        REP(j,x) g[(k-x)/y][j] = '.';
                        g[0][0] = 'c';
                        REP(i,r) {
                                REP(j,c) cout << g[i][j];
                                cout << endl;
                        }
                        return;
                }
        }
        if (m == r - 1 && m == c - 1) {
                if (m == 2) {
                        cout << "Impossible" << endl;
                        return;
                }
                REP(i,r) REP(j,c) g[i][j] = '.';
                REP(i,(m+1)/2) g[r-i-1][c-1] = '*';
                REP(i,m/2) g[r-i-1][c-2] = '*';
                g[0][0] = 'c';
                REP(i,r) {
                        REP(j,c) cout << g[i][j];
                        cout << endl;
                }
                return;
        }
        cout << "Impossible" << endl;
}

int main()
{
        int T, cas = 0;
        cin >> T;

        while (T--) {
                int r, c, m;
                cin >> r >> c >> m;
                cout << "Case #" << ++cas << ":" << endl;
                calc(r, c, m);
        }

        return 0;
}
