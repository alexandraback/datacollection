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

int i, j, k, m, n, l;

int main() {
    //freopen("x.in", "r", stdin);

	//freopen("C-small-1-attempt0.in", "r", stdin);
	//freopen("C-small-1-attempt0.out", "w", stdout);

	freopen("C-small-2-attempt0.in", "r", stdin);
	freopen("C-small-2-attempt0.out", "w", stdout);

	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		cerr << tt << endl;

		vector<pii> v;
		cin >> m; F0(i, m) {
			cin >> j >> l >> k;
			F0(t, l) {
				v.push_back(pii(j, k + t));
			}
		}
		int ans = SZ(v);
		F0(mask, 1 << SZ(v)) {
			bool good = true;
			F0(i, SZ(v)) if ((1<<i)&mask)
				F0(j, i) if ((1<<j)&mask) {
						if ((720LL - v[i].first) * v[i].second <= (360LL - v[j].first) * v[j].second) good = false;
					}
			if (good) ans = min(ans, SZ(v)-bc(mask));
		}
  		printf("Case #%d: ", tt);
		cout << ans << endl;
	}
	return 0;
}
