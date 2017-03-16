//{
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (i = 0; i < (int)(n); ++i)
#define FOR(i, n) for (i = 1; i <= (int)(n); ++i)
#define LIN(i, u) for (i = head[u]; ~i; i = nxt[i])
#define MP make_pair
#define PB push_back
#define MAX(a, b, c) max(a, max(b, c))
#define MIN(a, b, c) min(a, min(b, c))
#define all(x) (x).begin(), (x).end()
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
//#define pi 3.1415926
#define pi (atan(1.0) * 4)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void CIN(T &a) { cin >> a; }
template <class T> void CIN(T &a, T &b) { cin >> a >> b; }
template <class T> void CIN(T &a, T &b, T &c) { cin >> a >> b >> c; }
template <class T> void CIN(T &a, T &b, T &c, T &d) { cin >> a >> b >> c>> d; }
template <class T> void PI(T a) { cout << a << endl; }
template <class T> void PI(T a, T b) { cout << a << " " << b << endl; }
template <class T> void PIS(T a) { cout << a << " "; }
template <class T> T abs(T a) { return a < 0 ? -a : a; }

//}

int T;
int r, c, m;
char g[55][55];

void init() {
    int i, j;
    FOR(i, r) FOR(j, c) g[i][j] = '*';
}

void print() {
    int i, j;
    FOR(i, r) {
        FOR(j, c) printf("%c", g[i][j]);
        puts("");
    }
}

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    cin >> T;
    int ix = 0;
    while (T--)
    {
        printf("Case #%d:\n", ++ix);
        scanf("%d%d%d", &r, &c, &m);
        int i, j;
        int d = r * c - m;

        if (d == 1) {
            init();
            g[1][1] = 'c';
            print();
            continue;
        }

        if (r == 1) {
            printf("c");
            REP(i, d - 1) printf(".");
            REP(i, m) printf("*");
            puts("");
            continue;
        }

        if (c == 1) {
            puts("c");
            REP(i, d - 1) puts(".");
            REP(i, m) puts("*");
            continue;
        }

        if (min(r, c) == 2) {
            if (d < 4) puts("Impossible");
            else if (d % 2) puts("Impossible");
            else {
                d -= 4;
                init();
                g[1][1] = 'c';
                g[1][2] = g[2][1] = g[2][2] = '.';

                if (r == 2) {
                    int ix = 3;
                    while (d) {
                        g[1][ix] = g[2][ix] = '.';
                        d -= 2;
                        ++ix;
                    }
                }
                else {
                    int ix = 3;
                    while (d) {
                        g[ix][1] = g[ix][2] = '.';
                        d -= 2;
                        ++ix;
                    }
                }

                print();
            }
            continue;
        }

        if (d < 9) {
            if (d < 4) puts("Impossible");
            else if (d % 2) puts("Impossible");
            else {
                init();
                g[1][1] = 'c';
                g[1][2] = g[2][1] = g[2][2] = '.';
                if (d > 4) g[1][3] = g[2][3] = '.';
                if (d > 6) g[3][1] = g[3][2] = '.';
                print();
            }
        }
        else {
            init();
            int l = d / c;
            if (l <= 1) {
                if (d % 2) {
                    FOR(i, 3) FOR(j, 3) g[i][j] = '.';
                    int ix = 4;
                    d -= 9;
                    while (d) {
                        g[1][ix] = g[2][ix] = '.';
                        d -= 2;
                        ++ix;
                    }
                }
                else {
                    FOR(i, 2) FOR(j, 2) g[i][j] = '.';
                    int ix = 3;
                    d -= 4;
                    while (d) {
                        g[1][ix] = g[2][ix] = '.';
                        d -= 2;
                        ++ix;
                    }
                }
            }
            else {
                FOR(i, l) FOR(j, c) g[i][j] = '.';
                FOR(i, d % c) g[l + 1][i] = '.';
                if (d % c == 1) {
                    if (l == 2) {
                        g[l + 1][2] = g[l + 1][3] = '.';
                        g[1][c] = g[2][c] = '*';
                    }
                    else {
                        g[l][c] = '*';
                        g[l + 1][2] = '.';
                    }
                }
            }
            g[1][1] = 'c';
            print();
        }
    }
    return 0;
}
