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

const int N = 7;
const int inf = 1e9;

int n, m;
int a[N][N];
bool used[N][N];
vi di;
vi dj;

void dfs(int i, int j)
{
    if (a[i][j] < 0 || used[i][j]) return;
    used[i][j] = true;
    if (a[i][j] == 0)
    {
        forn (k, di.size())
            dfs(i + di[k], j + dj[k]);
    }
}

bool good(int x, int y)
{
    for1 (i, n)
        for1 (j, m)
        if (a[i][j] < 0)
        {
            forn (k, di.size())
            {
                a[i + di[k]][j + dj[k]]++;
            }
        }
    forn (i, N) forn (j, N) used[i][j] = true;
    for1 (i, n) for1 (j, m) used[i][j] = false;
    assert(a[x][y] >= 0);
    dfs(x, y);
    for1 (i, n)
        for1 (j, m)
            if (a[i][j] >= 0 && !used[i][j])
                return false;
    return true;
}

const bool CAN = false;

void wrAns()
{
    if (!CAN) return;
    for1 (i, n) {
        for1 (j, m)
        {
            if (i == n && j == m)
                cout << 'c';
            else
            if (a[i][j] < 0)
                cout << '*';
            else
                cout << ".";
        }
        cout << "\n";
    }
}


void wrAns2(int x, int y)
{
    for1 (i, n) {
        for1 (j, m)
        {
            if (i == x && j == y)
                cout << 'c';
            else
            if (a[i][j] < 0)
                cout << '*';
            else
                cout << ".";
        }
        cout << "\n";
    }
}

bool mysol(int n, int m, int q)
{
    forn (filled, n)
    for1 (r, n - filled)
    for1 (c, m)
    if (r * c + filled * m>= q)
    {
        int  rem = q;
        memset(a, 0, sizeof(a));
        for1 (i, filled)
        {
            for1 (j, m)
            {
                if (!rem) break;
                --rem;
                a[i][j] = -inf;
            }
        }
        for (int i = filled + 1; i <= filled + r; i++)
            for1 (j, c)
            {
                if (!rem) break;
                --rem;
                a[i][j] = -inf;
            }
        assert(!rem);
        if (good(n, m))
        {
            wrAns();
            return true;
        }
    }
    return false;
}

bool greedy(int n, int m, int q)
{
    bool res = false;
    int W = n * m;
    forn (msk, (1 << W))
    if (__builtin_popcount(msk) == q)
    {
        memset(a, 0, sizeof(a));
        forn (k, W)
            if ((1 << k) & msk)
            {
                int i = k;
                int j = i % m + 1;
                i /= m; i++;
                a[i][j] = -inf;
            }
        for1 (i, n)
        for1 (j, m)
        if (a[i][j] == 0) {
        if (good(i, j))
        {
            wrAns2(i, j);
            return true;
        }
        }
    }
    return res;
}

#define TEST "small"
int main() {
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (i != 0 || j != 0)
            {
                di.pb(i);
                dj.pb(j);
            }
#ifndef TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else // HOME
    freopen(TEST".in", "r", stdin);
    freopen(TEST".out", "w", stdout);
#endif

    int T;
	cin >> T;
    for1 (t, T)
    {
        int q;
        cin >> n >> m >> q;
        cout << "Case #" << t << ": " << "\n";
        bool findAns = greedy(n, m, q);
        if (findAns != mysol(n, m, q))
        {
            cerr << t << " " << findAns << endl;
        }
        if (!findAns)
            cout << "Impossible\n";
    }
    return 0;
}
