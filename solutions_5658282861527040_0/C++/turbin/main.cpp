#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cfloat>

using namespace std;

typedef long long ll;
typedef long long li;
typedef unsigned int uint;
typedef unsigned long long ull;

#define TASKNAME "prob"

ll solve(ll a, ll b, ll k, ll &exact)
{
	ll ans = 0; exact = 0;
	for (int i = 0; i < a; i++)
	for (int j = 0; j < b; j++)
	{
		ans += ((i & j) < k);
		exact += ((i & j) == k);
	}
	return ans;
}

const int step = 10;

ll solve2(ll a, ll b, ll k, ll pw)
{
	ll ms = (1 << pw) - 1;
	ll la = (a & ms), ha = a >> pw, lb = (b & ms), hb = b >> pw, lk = (k & ms), hk = k >> pw;
	ll exact = 0;
	ll ans = solve(ha, hb, hk, exact) << (pw + pw);
	if (pw > 0)
	{
		ans += solve2(ms + 1, ms + 1, lk, pw - step) * exact;
		ll tp = (ha & hb) << pw;
		if (tp < k)
			ans += solve2(la, lb, k - tp, pw - step);
		exact = 0;
		for (int i = 0; i < ha; i++)
			if ((i & hb) < hk) ans += lb << pw;
			else if ((i & hb) == hk) exact++;
		ans += solve2(ms + 1, lb, lk, pw - step) * exact;
		exact = 0;
		for (int i = 0; i < hb; i++)
			if ((i & ha) < hk) ans += la << pw;
			else if ((i & ha) == hk) exact++;
		ans += solve2(la, ms + 1, lk, pw - step) * exact;
	}
	return ans;
}

int main()
{
#ifdef DEBUG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	//ios_base::sync_with_stdio(0);
#endif

	int tests; scanf("%d\n", &tests);
	for (int ts = 0; ts < tests; ts++)
	{

		ll a, b, k;
		scanf("%lld%lld%lld", &a, &b, &k);
		printf("Case #%d: %lld\n", ts + 1, solve2(a, b, k, 20));
		/*
		int ans = 0, a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			ans += ((i & j) < k);
		printf("%d\n", ans);
		*/
	}
	
}
