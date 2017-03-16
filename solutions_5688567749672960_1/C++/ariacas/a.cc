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

vl p10(20, 1);
ll f(ll n) {
    if (n <= 0) return 0;
    if (n <= 9) return n;
    if (n % 10 == 0) return f(n-1) + 1;
    vi t;
    ll n1 = n;
    while (n1) {
        t.push_back(n1 % 10);
        n1 /= 10;
    }
    ll sum = 0;
    for (int i = 0; i < t.size(); ++i) {
        int x = min(i, (int)t.size() - i - 1);
        sum += t[i] * p10[x];
    }
    //if (n < c.size()) return c[n];
    //if (n % 10 == 0)
    ll nx = p10[t.size() - 1] - 1;
    return min(sum + 1 + f(nx), n-nx + f(nx));
}

vi c(1000001);
int main() {
    for (int i = 1; i < p10.size(); ++i) p10[i] = p10[i-1]*10;
    for (int i = 0; i < c.size(); ++i) c[i] = i;
    for (int i = 1; i < c.size(); ++i) {
        c[i+1] = min(c[i+1], c[i] + 1);
        int ri = rev(i);
        c[ri] = min(c[ri], c[i] + 1);
    }
    for (int i = 0; i < 100000; ++i) {
//        cerr << i << ' ' << c[i] << ' ' << f(i) << endl;
        assert(c[i] == f(i));
    }
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        ll n;
        cin >> n;
        ll res = f(n);
        if (n < c.size()) assert(res == c[n]);
        cout << f(n) << endl;
    }
    return 0;
}
