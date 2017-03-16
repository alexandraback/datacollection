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
const int MAXN = 100100;

double aa[MAXN];

int main()
{
	int T;
	int cn = 0;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);

	while (T--) {
		int A, B;

		scanf("%d%d", &A, &B);

		aa[0] = 1;
		for (int i = 1; i <= A; i++) {
			double x;
			scanf("%lf", &x);
			aa[i] = aa[i - 1] * x;
		}
		double ans = min(aa[A] * (B - A + 1) + (1 - aa[A]) * (B - A + B + 2), (double)(B + 2));
		for (int i = 1; i <= A; i++) {
			ans = min(ans, aa[A - i] * (B - A + 2 * i + 1) + (1 - aa[A - i]) * ((B - A) + 2 * i + B + 2));
		}
		printf("Case #%d: %.6f\n", ++cn, ans);
	}
	return 0;
}
