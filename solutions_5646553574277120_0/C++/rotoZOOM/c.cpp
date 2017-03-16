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

int mas[110];
int dp[110];
int v;

void doit(int a)
{
	for (int i = v - a; i >= 0; i--)
	{
		if (dp[i]) dp[i + a] = 1;
	}
}

void Solve()
{
	int i, j, k, n, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		int c, d;
		in_int3(c, d, v);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (i = 0; i < d; i++)
		{
			in_int1(mas[i]);
			doit(mas[i]);
		}

		int ret = 0;
		for (i = 1; i <= v; i++)
		{
			if (!dp[i])
			{
				doit(i);
				ret++;
			}
		}

		printf("Case #%d: %d\n", test, ret);
	}
}

int main()
{
#ifdef __LOCAL_RUN__
	#define _MAX_BUF_SIZE 32
	int _i = 0;
	char *_buf = new char[_MAX_BUF_SIZE];

	FILE *res_output = freopen("output.txt", "wt", stdout);
	while (true)
	{
		string _suffix = string(itoa(_i, _buf, 10)) + string(".txt");
		FILE *res_input = freopen((string("input-") + _suffix).c_str(), "rt", stdin);
		if (!res_input)
		{
			// the end
			break;
		}
		if (_i) printf("\n\n");
		printf("==== Case #%d =====\n", _i);
		Solve();
		_i++;
	}
#else
	Solve();
#endif
	return 0;
}