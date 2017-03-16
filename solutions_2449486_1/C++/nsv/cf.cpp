#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"

bool solve()
{
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    cin >> a;

    vvi r(n, vi(m, false));
    for (int h = 100; h >= 1; --h)
    {
        forn(i, n)
        {
            bool ok = true;
            forn(j, m)
                if (a[i][j] > h)
                    ok = false;
            if (ok)
                forn(j, m)
                    if (a[i][j] == h)
                        r[i][j] = true;
        }

        forn(j, m)
        {
            bool ok = true;
            forn(i, n)
                if (a[i][j] > h)
                    ok = false;
            if (ok)
                forn(i, n)
                    if (a[i][j] == h)
                        r[i][j] = true;
        }
    }

    forn(i, n)
        forn(j, m)
            if (!r[i][j])
                return false;
    return true;
}

int main()
{
    START
    // freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
        printf("Case #%d: %s\n", i + 1, solve() ? "YES" : "NO");

    END
    return 0;
}
/*******************************************
*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i] << " ";
    return os;
}
#endif