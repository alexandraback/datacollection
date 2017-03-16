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

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;

template <class T> T inline sqr(T x) {
        return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

const int N = 1e8;
int d[N];
void solve()
{
    int x;
    cin >> x;
    cout << d[x];
}


queue<int> q;

void upd(int x, int val)
{
    if (x < N && x > 0 && !d[x]) {
        d[x] = val;
        q.push(x);
    }
}

void prec()
{
    q.push(1);
    d[1] = 1;
    while (!q.empty())
    {
        
        int v = q.front();
        q.pop();
        int c = d[v];
        upd(v + 1, c + 1);
        vi x;
        while (v)
        {
            x.pb(v % 10);
            v /= 10;
        }
        forn (i, x.size())
            v = v * 10 + x[i];
        upd(v, c + 1);
    }
}

int main()
{
    prec();
#ifdef HOME
    freopen("A-small.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for1 (t, T)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
