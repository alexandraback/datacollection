#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))
#define so(a) sort((a).begin(), (a).end())
#define rso(a) sort((a).rbegin(), (a).rend())
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int mas[1010];

ll rev(ll a)
{
	ll r = 0;
	while (a)
	{
		r *= 10ll;
		r += a % 10;
		a /= 10;
	}

	return r;
}

ll dp[1000000];
ll n;

ll doit(ll a)
{
	if (a == n) return 0;
	ll& res = dp[a];
	if (res == -1)
	{
		res = doit(a + 1) + 1;
		if (rev(a) <= n && rev(a)>a)
		{
			ll ret = doit(rev(a)) + 1;
			res = min(res,ret);
		}
	}
	return res;
}

void Solve()
{
	int i, j, k;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%lld", &n);
		printf("Case #%d: ", test);

		if (n < 21)
		{
			printf("%lld\n", n);
		}
		else
		{
			ll cnt = 11;
			ll a = 11;

			memset(dp, -1, sizeof(dp));
			cnt = doit(a) + 11;

			/*
			ll m = 100;
			while (n >= m)
			{
				cnt += 9 - (a % 10);
				a = (a / 10) * 10 + 9;
				a = rev(a);
				cnt++;
				cnt += m - a;
				a = m;
				m *= 10ll;
			}

			m /= 10;
			ll c = n / m;
			while ((a%10) < c)
			{
				cnt++;
				a++;
			}
			if (a % 10 > 0 && rev(a) > n)
			{
				cnt--;
				a--;
			}

			if (a % 10 > 0 && rev(a) > a)
			{
				a = rev(a);
				cnt++;
			}

			cnt += n - a;
			*/
			printf("%lld\n", cnt);
		}
	}
}

int main()
{
#ifdef __LOCAL_RUN__
	#define _MAX_BUF_SIZE 32
	int _i = 0;
	char *_buf = new char[_MAX_BUF_SIZE];

	FILE *res_output = freopen ("output.txt","wt",stdout);
	while(true)
	{
		string _suffix = string(itoa(_i,_buf,10))+string(".txt");
		FILE *res_input = freopen ((string("input-")+_suffix).c_str(),"rt",stdin);
		if (!res_input)
		{
			// the end
			break;
		}
		if (_i) printf ("\n\n");
		printf ("==== Case #%d =====\n", _i);
		Solve();
		_i++;
	}
#else
	Solve();
#endif
	return 0;
}