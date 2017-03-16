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

int i, j, k, m, n, l, ans, a[1005], b[1005];
char ss[1000002];

int main() {
//	freopen("b.in", "r", stdin);

//    freopen("B-small-attempt0.in", "r", stdin);
//    freopen("B-small-attempt0.out", "w", stdout);

    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        cin >> n;
        F0(i,n) cin >> a[i] >> b[i];
        ans = n;
        m = 0;
        k = 0;

        while (k != n)
        {
            F0(i,n) if (b[i] <= m)
            {
                k++;
                b[i] = inf;
                if (a[i] == inf) m++; else
                {
                    m += 2;
                    a[i] = inf;
                }
                break;
            }
            if (i != n) continue;
            int best = -1, at = -1;
            F0(i,n) if (a[i] <= m && b[i] >= best)
            {
                best = b[i];
                at = i;
            }
            if (at == -1) break;
            ans++;
            a[at] = inf;
            m++;
        }

        printf("Case #%d: ", tt);

        if (k == n) cout << ans << endl;
        else cout << "Too Bad" << endl;
	}
	
	return 0;
}
