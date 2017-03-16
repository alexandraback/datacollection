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
#define CL(a,x) memset(x, a, sizeof(x))
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];

int main() {
    //freopen("b.in", "r", stdin);

    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);

    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        //cerr << tt << endl;
        double C, F, X;
        cin >> C >> F >> X;
        double ans = X / 2.0;
        double t = 0.0;
        for (i = 0; i < 1000000; i++) {
            t += C / (2+i*F);
            ans = min(t + X / (2+F+i*F), ans);
        }

		printf("Case #%d: ", tt);
        printf("%.7lf\n", ans);
	}
	return 0;
}
