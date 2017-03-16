#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const double EPS = 1e-9;

const double MX = 3e18;

void solve()
{
	ll R, T;
	scanf("%lld%lld", &R, &T);
	ll x = 2*R + 1;

	ll l = 0;
	ll r = T;
	while (l + 1 < r)
	{
		ll m = (l + r)/2;
		double dcnt = m;
		double dlst = (x + (dcnt-1)*4);
		double dnv = dcnt*(x + dlst)/2;
		if (dnv > MX)
		{
			r = m;
			continue;
		}
		ll cnt = m;
		ll lst = (x + (cnt-1)*4);
		ll nv = cnt*(x + lst)/2;
		if (nv > T)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}

	printf("%lld\n", l);
}
int main()
{
	freopen("Atest.txt", "r", stdin);
	freopen("Aout.txt", "w", stdout);

	int T;
	scanf ("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		//fprintf(stderr, "%d/%d\n", i+1, T);
		solve();
	}
	return 0;
}