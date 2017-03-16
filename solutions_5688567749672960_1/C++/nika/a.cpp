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
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, l;

ll n;

ll rev(ll n) {
	vector<int> v;
	while (n > 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	ll ret = 0;
	F0(i,SZ(v)) ret = ret * 10 + v[i];
	return ret;
}

int main() {
    //freopen("x.in", "r", stdin);

	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		//cerr << tt << endl;

		cin >> n;

		int ans = 0;
		while (n >= 10) {
			int dc = 0;
			ll p = 1;
			while (p <= n) {
				p *= 10;
				dc++;
			}
			ll p1 = 1, p2 = 1;
			F0(i, dc / 2) {
				p1 *= 10;
			}
			F0(i, (dc + 1) / 2) {
				p2 *= 10;
			}
			if (n % p2 == 0) {
				n--;
				ans++;
				continue;
			}
			if (n / p2 == p1 / 10) {
				ans += n % p2;
				n -= n % p2;
				continue;
			}
			ans += (n % p2 - 1);
			n -= (n % p2 - 1);
			ans++;
			n = rev(n);

		}
		ans += n;
  		printf("Case #%d: ", tt);
		cout << ans << endl;
	}
	return 0;
}
