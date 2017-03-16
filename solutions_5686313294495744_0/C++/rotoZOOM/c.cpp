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

int topic[20][2];
int mask0, mask1;
// int cnt0[20], cnt1[20];
int dp[1 << 16];
int total;
int n;

int go(int mask)
{
	if (mask == total) return 0;
	int& ans = dp[mask];
	if (ans == -1)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (!(mask&(1 << i)))
			{
				int t0 = topic[i][0];
				int t1 = topic[i][1];
				// is fake?
				int add = (mask0 & (1 << t0)) && (mask1 & (1 << t1));
				// cnt0[t0]++;
				// cnt1[t1]++;
				int prev_mask0 = mask0;
				int prev_mask1 = mask1;
				mask0 |= (1 << t0);
				mask1 |= (1 << t1);
				int ret = go(mask | (1 << i)) + add;
				mask0 = prev_mask0;
				mask1 = prev_mask1;
				ans = max(ans, ret);
			}
		}
	}

	return ans;
}

void Solve()
{
	int i, j, k, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		fprintf(stderr, "Process test #%d\n", test);
		in_int1(n);
		char b[2][32];
		map<string, int> t0, t1;
		for (i = 0; i < n; i++)
		{
			in_str(b[0]);
			in_str(b[1]);
			if (t0.count(b[0]) == 0)  t0[b[0]] = t0.size();
			if (t1.count(b[1]) == 0)  t1[b[1]] = t1.size();
			topic[i][0] = t0[b[0]];
			topic[i][1] = t1[b[1]];
		}

		mask0 = mask1 = 0;
		mset(dp, -1);
		// mset(cnt0, 0);
		// mset(cnt1, 0);
		total = (1 << n) - 1;
		printf("Case #%d: %d", test, go(0));
		printf("\n");
	}
}

int main()
{
#ifdef __LOCAL_RUN__
	FILE *res_output = freopen("output.txt", "wt", stdout);
	FILE *res_input = freopen("input.txt", "rt", stdin);
	Solve();
#else
	Solve();
#endif
	return 0;
}