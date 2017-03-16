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
    freopen("a.in", "r", stdin);
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
    string s;
    cin >> n >> s;
    int cnt = 0;
    int sum = 0;
    forn (i, n + 1)
    {
        if (s[i] > '0')
            cnt = max(cnt, i);
        sum += (s[i] - '0');
        cnt += (s[i] - '0');
    }
    printf("Case #%d: %d\n", test++, cnt - sum);
    return 0;
}
