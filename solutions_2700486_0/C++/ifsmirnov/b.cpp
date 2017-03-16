#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 1000500;

ld d[2000][2000];
int n, x, y;

ld solve()
{
    cin >> n >> x >> y;
    int mp = abs(x)+y, h = y;
    int p = 0;

    for (;; p += 2) {
        int lvl = p*2 + 1;
        if (lvl < n)
            n -= lvl;
        else
            break;
    }

    if (mp > p)
        return 0;
    else if (mp < p)
        return 1;

    if (p*2 + 1 == n)
        return 1;

    if (p == h)
        return p*2 + 1 == n ? 1 : 0;

    forn(i, p+1) forn(j, p+1) d[i][j] = 0;
    d[0][0] = 1;
    fore(s, 0, 2*p-1) fore(i, 0, min(s, p)) {
        int j = s-i;
        if (j > p) continue;

        ld pi, pj;
        if (i == p) pi = 0, pj = 1;
        else if (j == p) pi = 1, pj = 0;
        else pi = 0.5, pj = 0.5;

        d[i+1][j] += d[i][j] * pi;
        d[i][j+1] += d[i][j] * pj;
    }

    ld res = 0;
    forn(i, p+1) forn(j, p+1) if (i+j == n && i > h)
        res += d[i][j];

    return res;
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout.precision(10);
    cout << fixed;


    int t;
    cin >> t;
    forn(i, t) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
