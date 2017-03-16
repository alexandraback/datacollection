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

int w, m;
int dpg[1 << 20];
int dps[11][1 << 20];

bool ok(int p, int mask)
{
	for (int i = 0, j = 0; i < m; i++, j += 2)
	{
		bool zone = i >= p && i < p + w;
		if ((mask&(1 << j)) && !zone) return false;
		else if ((mask & (1 << (j + 1))) && zone) return false;
	}

	return true;
}

int guess(int mask);

int shoot(int p, int mask)
{
	int& best = dps[p][mask];
	if (best == -1)
	{
		best = 0;
		for (int i = 0; i <= m - w; i++)
		{
			if (ok(i, mask))
			{
				int t = mask;
				if (p >= i && p < i + w) t |= 1 << (p*2);
				else t |= 1 << (p*2 + 1);
				int ret = guess(t);
				best = max(best, ret);
			}
		}
	}

	return best;
}

int guess(int mask)
{
	int i, j, cnt = 0;
	for (i = 0; i < m; i++)
	{
		if (mask&(1 << (i * 2))) cnt++;
	}
	if (cnt == w) return 0;
	
	int& best = dpg[mask];
	if (best == -1)
	{
		best = 1000000;
		for (i = 0, j = 0; i < m; i++, j += 2)
		{
			if (!((mask >> j) & 0x3))
			{
				int ret = 1 + shoot(i, mask);
				best = min(best, ret);
			}
		}
	}

	return best;
}

void Solve()
{
	int i, j, k, n;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		in_int3(n, m, w);
		memset(dpg, -1, sizeof(dpg));
		memset(dps, -1, sizeof(dps));
		printf("Case #%d: %d\n", test, guess(0));
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