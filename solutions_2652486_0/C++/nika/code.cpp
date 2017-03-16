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
#include <cstring>
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
ll p[10005];

int main() {
    //freopen("x.in", "r", stdin);

  //freopen("B-small-attempt3.in", "r", stdin);
  //freopen("B-small-attempt3.out", "w", stdout);

   freopen("C-small-1-attempt0.in", "r", stdin);
   freopen("C-small-1-attempt0.out", "w", stdout);

//    freopen("B-large.in", "r", stdin);
//    freopen("B-large.out", "w", stdout);

    int tt, tn; cin >> tn;
    F1(tt,tn) {
        cin >> l >> n >> m >> k;
        printf("Case #%d:\n", tt);
        while (l--)
        {
            F0(i,k) cin >> p[i];
            ll z = 0, cnt = n, n2 = 0;
            F0(i,k) z = max(z, p[i]);
            while (z % 5 == 0) { cout << 5; cnt--; z /= 5; }
            while (z % 3 == 0) { cout << 3; cnt--; z /= 3; }
            while (z % 2 == 0) { n2++; z /= 2; }
            if (cnt < 0) throw 9;
            while (cnt > 0)
            {
                if (n2 > cnt) { cout << 4; n2 -= 2; }
                else { cout << 2; n2 -= 1; }
                cnt--;
            }
            cout << endl;
        }
    }

    return 0;
}
