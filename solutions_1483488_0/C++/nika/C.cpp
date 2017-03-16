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

int i, j, k, m, n, l, ans, p10, d, A, B;
char ss[1000002];

int main() {
//	freopen("c.in", "r", stdin);

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

//	freopen("C-large.in", "r", stdin);
//	freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        cin >> A >> B;
        d = 0;
        p10 = 1;
        k = A;
        while (k > 0)
        {
            p10 *= 10;
            d++;
            k /= 10;
        }
        ans = 0;
        int o = 0;
        for (i = A; i <= B; i++)
        {
            k = i;
            set<int> S;
            S.insert(i);
            F0(j,d-1) {
                k = k / 10 + k%10 * p10 / 10;
                if (k >= A && k <= B) S.insert(k);
            }
            ans += SZ(S)-1;
        }
		printf("Case #%d: ", tt);
        cout << ans/2 << endl;
	}
	
	return 0;
}
