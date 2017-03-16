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

void Solve()
{
	int i, j, k, n, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		int c, s;
		in_int3(k, c, s);

		printf("Case #%d:", test);
		vector<ll> ans;
		ll offset = 0;
		ll block_size = 1;
		for (i = 0; i < c - 1; i++) block_size *= k;
		ll bs = block_size;

		for (i = 0; i < k; i++)
		{
			offset += bs * i;
			if (bs == 1 || i == k - 1)
			{
				ans.push_back(offset + 1);
				offset = 0;
				bs = block_size;
			}
			else
			{
				bs /= k;
			}
		}

		if (ans.size() > s) printf(" IMPOSSIBLE");
		else
		{
			for (i = 0; i < ans.size(); i++)
			{
				printf(" %lld", ans[i]);
			}
		}

		printf("\n");
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