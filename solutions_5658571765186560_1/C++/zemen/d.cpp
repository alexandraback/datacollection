#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
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
    freopen("d.in", "r", stdin);
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
    int x, r, c;
    cin >> x >> r >> c;
    bool win = true;
    if (r > c)
        swap(r, c);
    if ((r * c) % x)
        win = false;
    if (x == 3 && r == 1)
        win = false;
    if (x == 4 && r <= 2)
        win = false;
    if (x == 5 && r <= 2)
        win = false;
    if (x == 5 && r == 3 && c == 5)
        win = false;
    if (x == 6 && r <= 3)
        win = false;
    if (x > 6)
        win = false;
    printf("Case #%d: %s\n", test++, (win ? "GABRIEL" : "RICHARD"));
    return 0;
}
