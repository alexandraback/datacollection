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
double a[1005], b[1005];
char ss[1000002];

int get(double* a, double* b) {
    j = 0;
    F0(i,n) {
        while (b[j] <= a[i] && j < n) j++;
        if (j == n) break;
        j++;
    }
    return i;
}

int main() {
//    freopen("d.in", "r", stdin);
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);

//	freopen("D-large.in", "r", stdin);
//	freopen("D-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        //cerr << tt << endl;
        cin >> n;
        F0(i,n) cin >> a[i];
        F0(i,n) cin >> b[i];
        sort(a,a+n); sort(b,b+n);
        printf("Case #%d: %d %d\n", tt, get(b,a), n-get(a,b));
	}
	return 0;
}
