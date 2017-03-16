#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("b.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int test = 1;

int solve()
{
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, n)
        cin >> a[i];
    int res = INF;
    forab (m, 1, 1001)
    {
        int cres = m;
        forn (i, n)
            cres += (a[i] + m - 1) / m - 1;
        res = min(res, cres);
    }
    printf("Case #%d: %d\n", test++, res);
    return 0;
}
