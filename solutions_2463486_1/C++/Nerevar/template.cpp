#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;

const int SMAX = 10000007;

bool p[SMAX], p2[SMAX];

bool is_pal(ll x)
{
    int s[20];
    int len = 0;
    while (x)
    {
        s[len++] = x % 10;
        x /= 10;
    }

    forn(i, len) if (s[i] != s[len - i - 1]) return false;

    return true;
}

void precalc()
{
    for (int i = 1; i < SMAX; i++)
    {
        p[i] = is_pal(i);
        if (p[i]) p2[i] = is_pal((ll)(i) * i);
    }
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    ll a, b;
    cin >> a >> b;
    int ans = 0;
    for (ll i = 1; i < SMAX; i++)
    {
        if (i * i < a) continue;
        if (i * i > b) break;
        if (p2[i]) ans++;
    }

    cout << ans << endl;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    precalc();
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
