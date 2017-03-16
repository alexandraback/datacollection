#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
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
#include <ctime>
#include <cstring>
#include <iterator>
#define REP(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define foreach(itr,c) for(decltype((c).begin()) itr=(c).begin(); itr != (c).end(); itr++)

using namespace std;

//typedef __int64 ll;
//typedef unsigned __int64 ull;
typedef long long ll;
typedef unsigned long long ull;

template<typename T>
inline T ABS(T a) { return a > 0 ? a : -a; }
template<typename T>
inline T MIN(T a, T b) { return a < b ? a : b; }
template<typename T>
inline T MAX(T a, T b) { return a > b ? a : b; }
template<typename T>
inline T CHKMIN(T &a, T b) { if(a > b) a = b; return a; }
template<typename T>
inline T CHKMAX(T &a, T b) { if(a < b) a = b; return a; }
template<typename T>
inline void SWAP(T &a, T &b) { static T c; c = a; a = b; b = c; }

template<typename T, typename... T0>
T MAX(T a, T b, T0... c) { return a > b ? MAX(a, c...) : MAX(b, c...); }
template<typename T, typename... T0>
T MIN(T a, T b, T0... c) { return a < b ? MIN(a, c...) : MIN(b, c...); }

template<typename T, int n>
void myin(T a[]) { REP(i, 0, n) cin >> a[i]; }
template<typename T>
void myin(T &a) { cin >> a; }

template<typename T>
void print(T a) { cout << a << ' '; }
template<typename T, typename... T0>
void print(T a, T0... b) { print(a); print(b...); }
template<typename T>
void println(T a) {cout << a << endl;}
template<typename T, typename... T0>
void println(T a, T0... b) { print(a); println(b...); }

typedef int (*CMP)(const void *, const void *);

int w, h, in[200][200], q[40000][2];

int cmp(int *a, int *b) {
    return in[a[0]][a[1]] - in[b[0]][b[1]];
}

int g(int x, int y, int z) {
    int min = in[x][y];
    if(z == 0) {
        REP(i, 0, h) if(in[x][i] != -1) CHKMAX(min, in[x][i]);
    } else {
        REP(i, 0, w) if(in[i][y] != -1) CHKMAX(min, in[i][y]);
    }
    return min;
}

int hh(int x, int y, int z) {
    if(z == 0) {
        REP(i, 0, h) if(in[x][i] != -1) in[x][i] = -1;
    } else {
        REP(i, 0, w) if(in[i][y] != -1) in[i][y] = -1;
    }
}

int f() {
    int m = 0;
    REP(i, 0, w) REP(j, 0, h) {
        q[m][0] = i;
        q[m][1] = j;
        ++m;
    }
    qsort(q, m, sizeof(q[0]), (CMP)cmp);
    REP(i, 0, m) {
        int x = q[i][0], y = q[i][1], flag = 0;
        if(in[x][y] == -1) continue;
        if(g(x, y, 0) == in[x][y]) flag = 1, hh(x, y, 0);
        if(g(x, y, 1) == in[x][y]) flag = 1, hh(x, y, 1);
        if(!flag) return 0;
    }
    return 1;
}

int main() {
    int t;
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    cin >> t;
    REP(tt, 1, t + 1) {
        cin >> w >> h;
        REP(i, 0, w) REP(j, 0, h) scanf("%d", in[i] + j);
        int ans = f();
        printf("Case #%d: ", tt);
        puts(!ans ? "NO" : "YES");
    }
    return 0;
}
