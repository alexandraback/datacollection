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
ll p[10005], d[2][30005];

int main() {
//   freopen("x.in", "r", stdin);

  //freopen("B-small-attempt3.in", "r", stdin);
  //freopen("B-small-attempt4.out", "w", stdout);

    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int tt, tn; cin >> tn;
    F1(tt,tn) {
        ll E, R, ans = 0;
        cin >> E >> R >> n;
        if (R > E) R = E;
        F1(i,n)
        {
            cin >> p[i];
        }
        memset(d, 0, sizeof(d));
        set<ll> S;
        for (i = 0; i <= n; i++)
            if (i * R <= E) S.insert(i*R);
        for (i = 0; i <= n; i++)
            if (E - i * R >= 0) S.insert(E - i * R);
        vector<ll> V(S.begin(), S.end());
        m = SZ(V);

        d[0][m-1] = 0;
        int i1, i2;
        F1(i,n-1)
        {
            i2 = i%2;
            i1 = 1-i2;
            // <--
            memset(d[i2], 0, sizeof(d[i2]));
            for (j = m-1; j >= 1; j--)
                if (d[i1][j] + (V[j]-V[j-1])*p[i] > d[i1][j-1])
                    d[i1][j-1] = d[i1][j] + (V[j]-V[j-1])*p[i];
            for (j = 0; j < m; j++) if (V[j] + R <= E && d[i1][j] > 0)
            {
                ll v2 = V[j] + R, j2 = -1;
                if (V[j+1] == v2) j2 = j+1;
                else if (j+2 < m && V[j+2] == v2) j2 = j+2;
                if (j2 != -1)
                {
                    d[i2][j2] = d[i1][j];
                }
            }
        }
        ans = 0;
        for (j = 0; j < m; j++) ans = max(ans, d[i2][j]+V[j]*p[n]);
        printf("Case #%d: ", tt);
        cout << ans << endl;
    }

    return 0;
}
