#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

#define TEST "small"

int A, B, K;
i64 d[32][2][2][2];

int bit(int x, int p)
{
    return (x >> p) & 1;
}

int f(int p, bool a, bool b, bool k)
{
    if (p == -1) return 1;
    if (d[p][a][b][k] != -1) return d[p][a][b][k];
    vi cand1, cand2;
    cand1.pb(0);
    if (!a || bit(A, p))
        cand1.pb(1);
    cand2.pb(0);
    if (!b || bit(B, p))
        cand2.pb(1);
    i64 res = 0;
    for (int ca : cand1)
        for (int cb: cand2)
        {
            int r = ca & cb;
            if (k && r > bit(K, p))
                continue;
            res += f(p - 1, a & (ca == bit(A, p)), b & (cb == bit(B, p)), k & (r == bit(K, p)));
        }

    d[p][a][b][k] = res;
    return res;
}

void solve()
{
    cin >> A >> B >> K;
    A--, B--, K--;
    forn (i, 32) forn (i1, 2) forn (i2, 2) forn (i3, 2) d[i][i1][i2][i3] = -1;
    cout << f(30, 1, 1, 1) << "\n";
}

int main() {
#ifndef TEST
	freopen("input.txt", "r", stdin);
#else 
    freopen(TEST".in", "r", stdin);
    freopen(TEST".out", "w", stdout);
#endif
    int T;
    cin >> T;
    for1 (t, T)
	{
		cout << "Case #" << t << ": ";
	    solve();
    }
	return 0;
}
