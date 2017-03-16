#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <deque>
#include <ctime>
#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

#define endl '\n'

#define forr(i, n) for(ll (i) = 0LL; (i) < (n); (i)++)
#define mp3(a, b, c) mp(a, mp(b, c))

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;
typedef vector < pll > vll;

int INT_MAX_VAL = (int)  0x3F3F3F3F;
int INT_MIN_VAL = (int) -0x3F3F3F3F;
ll LONG_MAX_VAL = (ll)   0x3F3F3F3F3F3F3F3F;
ll LONG_MIN_VAL = (ll)  -0x3F3F3F3F3F3F3F3F;

#define MAXN 500006
#define MOD 1000000007

void solve()
{
    ll n, m; cin >> n >> m;

    ll max_val = (1LL << (n - 2));
//    cout << max_val << " " << m << endl;
    if (m > max_val) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << "POSSIBLE" << endl;

    string res(n, '0');

    if (m & (1LL << (n - 2))) {
        res[n - 1] = '1';
        --m;
    }

    for (int j = 0; j < n; ++j) {
        if (m & (1LL << j)) {
            res[n - j - 2] = '1';
        }
    }
    cout << res << endl;

    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > i) {
                cout << "1";
            } else {
                cout << "0";
            }

        }
        cout << endl;
    }

    cout << string(n, '0') << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
