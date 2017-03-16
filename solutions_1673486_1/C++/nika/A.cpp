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

int i, j, k, m, n, l;
double p[100005], pp[100005], ans;
char ss[1000002];

int main() {
//	freopen("a.in", "r", stdin);

//    freopen("A-small-attempt0.in", "r", stdin);
//    freopen("A-small-attempt0.out", "w", stdout);

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        cin >> m >> n;
        F1(i,m) cin >> p[i];
        pp[0] = 1.0;
        F1(i,m) pp[i] = pp[i-1] * p[i];
        ans = 2 + n;
        for (k = 0; k <= m; k++)
        {
            ans = min(ans, pp[k]*(m-k+n-k+1) + (1-pp[k])*(m-k+n-k+n+2));
        }

        printf("Case #%d: %.10lf\n", tt, ans);
	}
	
	return 0;
}
