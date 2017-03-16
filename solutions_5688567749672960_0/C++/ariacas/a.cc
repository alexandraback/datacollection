#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

ll rev (ll x) {
    ll res = 0;
    while (x) {
        res = 10*res + x%10;
        x /= 10;
    }
    return res;
}

ll f(ll n) {
    return n;
}

int main() {
    vi c(1000001);
    for (int i = 0; i < c.size(); ++i) c[i] = i;
    for (int i = 1; i < c.size(); ++i) {
        c[i+1] = min(c[i+1], c[i] + 1);
        int ri = rev(i);
        c[ri] = min(c[ri], c[i] + 1);
    }
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int n;
        cin >> n;
        if (n < c.size()) cout << c[n] << endl;
        else cout << f(n) << endl;
    }
    return 0;
}
