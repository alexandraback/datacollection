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

int n;
i64 s;
i64 a[maxn];

int solve()
{
    cin >> s >> n;
    forn(i, n) cin >> a[i];
    sort(a, a+n);
    int mn = inf, acc = 0;

    if (s == 1)
        return n;

    forn(i, n) {
        //cout << i << ": " << s << endl;
        mn = min(mn, acc + (n-i));
        while (s <= a[i])
            acc++, s += s-1;
        s += a[i];
    }
    mn = min(mn, acc);
    return mn;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    forn(i, t)
        cout << "Case #" << i+1 << ": " << solve() << endl;


#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
