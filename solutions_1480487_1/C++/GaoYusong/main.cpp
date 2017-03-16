#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <list>

using namespace std;

//GyS Loves Algorithm
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define mk(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define rep(x, n) for (int x = 0; x < n; x++)
#define range(x, a, b)for (int x = a; x <= b; x++)
#define sz(x) x.size()
#define setv(x, y) memset(x, y, sizeof(x))
#define repi(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pl() printf("\n")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int aa[1100];
double ans[1100];
vector<int> bb;
const double E = 1e-12;

inline
int dblcmp(double x)
{
	if (x > -E && x < E)
		return 0;
	return x > 0 ? 1 : -1;
}

double solve(double les)
{
	double l = 0, r = 21000;
	while (r - l > 1e-10) {
		double mid = (r + l) / 2;
		double tmp = les;
		bool ok = true;
		for (int i = 0; i < bb.size(); i++) {
			double need = mid - bb[i];
			if (dblcmp(tmp - need) >= 0) {
				tmp -= max(0.0, need);
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return l;
}

int main()
{
	int T;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	int cn = 0;
	while (T--) {
		int n;

		scanf("%d", &n);
		int base = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &aa[i]);
			base += aa[i];
		}
		for (int i = 0; i < n; i++) {
			bb.clear();
			for (int j = 0; j < n; j++) {
				if (i != j) {
					bb.push_back(aa[j]);
				}
			}
			sort(bb.begin(), bb.end());
			double l = 0, r = 1;
			while (r - l > 1e-10) {
				double mid = (l + r) / 2;
				double les = (1 - mid) * base;
				double ret = solve(les);
				if (aa[i] + base * mid >= ret) {
					r = mid;
				} else {
					l = mid;
				}
			}
			ans[i] = r;
		}
		printf("Case #%d:", ++cn);
		for (int i = 0; i < n; i++) {
			ans[i] = max(ans[i], 0.0);
			printf(" %.10f", ans[i] * 100);
		}
		printf("\n");
	}
	return 0;
}
