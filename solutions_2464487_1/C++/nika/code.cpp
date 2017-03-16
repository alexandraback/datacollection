#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];

int main() {
//    freopen("x.in", "r", stdin);

//  freopen("A-small-attempt0.in", "r", stdin);
//  freopen("A-small-attempt1.out", "w", stdout);

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int tt, tn; cin >> tn;
    F1(tt,tn) {
        ll r, t;
        cin >> r >> t;
        ll P = 0, Q = 1000000000, R;
        while (P < Q)
        {
            R = (P + Q + 1) / 2;
            ll s = 2*R*r - 3*R + 4 * R * (R+1) / 2;
            if (R >= t / r) s = t+1;
            if (s <= t) P = R; else Q = R-1;
        }
        printf("Case #%d: ", tt);
        cout << P << endl;
    }

    return 0;
}
