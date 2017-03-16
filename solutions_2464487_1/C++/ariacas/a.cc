#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        ll R, t;
        cin >> R >> t;
        ll l = 0, r = min(t+1, (ll)1e13);
        while (r - l > 1) {
            ll x = (l+r) / 2;
            if (t / x < 1+2*R+2*(x-1)) {
                r = x;
                continue;
            }
            if (t >= x+2*R*x+2*x*(x-1))
                l = x;
            else r = x;
        }
        printf("Case #%d: %lld\n", test, l);
    }
    return 0;
}
