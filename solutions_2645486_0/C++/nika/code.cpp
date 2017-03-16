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
ll h[10005];
pii p[10005];

ll d[15][15];

int main() {
//    freopen("x.in", "r", stdin);

  freopen("B-small-attempt3.in", "r", stdin);
  freopen("B-small-attempt3.out", "w", stdout);

//    freopen("B-large.in", "r", stdin);
//    freopen("B-large.out", "w", stdout);

    int tt, tn; cin >> tn;
    F1(tt,tn) {
        ll E, R, ans = 0;
        cin >> E >> R >> n;
        F1(i,n) h[i] = 0;
        F0(i,n)
        {
            cin >> p[i].first;
            p[i].second = i + 1;
        }
        /*
        sort(p,p+n);
        for (i = n-1; i >= 0; i--)
        {
            ll sum = 0;
            ll s = E;
            for (j = 1; j <= n; j++)
            {
                sum += h[j];
                if (j >= p[i].second) s = min(s, (j-1)*R + E - sum);
            }
            h[p[i].second] += s;
            ans += p[i].first*s;
        }
        */
        if (R > E) R = E;
        memset(d, 0, sizeof(d));
        for (i = 0; i < n; i++)
            for (j = R; j <= E; j++)
            {
                for (k = 0; k <= j; k++)
                {
                    int j2 = min(j-k+R, E);
                    d[i+1][j2] = max(d[i+1][j2], d[i][j] + k*p[i].first);
                }
            }
        ans = d[n][R];
        printf("Case #%d: ", tt);
        cout << ans << endl;
    }

    return 0;
}
