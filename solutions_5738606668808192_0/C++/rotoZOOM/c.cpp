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
#define mset(a,n) memset(a,n,sizeof(a))
#define readints(mas,n) for (int _i=0;_i<(n);_i++) in_int1((mas)[_i])
#define readdoubles(mas,n) for (int _i=0;_i<(n);_i++) scanf("%lf", &(mas)[_i])
#define unq(src) src.erase(unique((src).begin(), (src).end()), (src).end())
#define MOD 1000000007
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int p[65536];
ll dp[65536];
int np;

void Solve()
{
	int i, j, k, n, m, base;
	int mas[64];
	ll ans[64];

	np = 0;
	for (i = 2; i < 65636; i++)
	{
		for (j = 2; j*j <= i && i%j!=0; j++);
		if (j*j > i)
		{
			p[np] = i;
			dp[np++] = 1ll * i * i;
		}
	}

	printf("Case #1:\n");
	int tests;
	in_int3(tests, n, m);
	ll b = (1ll << (n-1)) + 1ll;
	for (i = 0; i < (1 << (n - 2)); i++)
	{
		ll a = b | (i << 1);
		for (j = 0; j < n; j++)
		{
			mas[j] = a & 1;
			a >>= 1;
		}

		for (base = 2; base <= 10; base++)
		{
			ll val = 0;
			ll bb = 1;
			for (j = 0; j < n; j++)
			{
				if (mas[j]) val += bb;
				bb *= base;
			}
			for (j = 0; j<np && dp[j] <= val && val%p[j] != 0; j++);
			if (dp[j] > val || j >= np) break;
			ans[base - 2] = p[j];
		}

		if (base > 10)
		{
			for (j = n - 1; j >= 0; j--) printf("%d", mas[j]);
			for (j = 0; j < 9; j++) printf(" %lld", ans[j]);
			printf("\n");
			m--;
			if (!m) break;
		}
	}
}

int main()
{
#ifdef __LOCAL_RUN__
#define _MAX_BUF_SIZE 32
	FILE *res_output = freopen("output.txt", "wt", stdout);
	FILE *res_input = freopen("input.txt", "rt", stdin);
	Solve();
#else
	Solve();
#endif
	return 0;
}