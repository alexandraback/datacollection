#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

ll gcd(ll a, ll b) {
	if (b>a) return gcd(b, a);
	return (b==0) ? a : gcd(b, a%b);
}

ll p, q;

void solve() {
	scanf("%lld/%lld", &p, &q);
	ll d = gcd(p, q);
	p /= d; q /= d;
	ll x = q;
	while (x%2==0) x/=2;
	if (x!=1) {
		printf("impossible\n");
		return ;
	}
	ll y = (1LL << 40);
	int k = 40;
	while (q<y) {
		q *= 2; p *= 2;
	}
	while (p > 1) {
		p /= 2; q/= 2; k--;
	}
	printf("%d\n", k);
}

int main()
{
	int t;
	scanf("%d", &t);
	REP (i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
