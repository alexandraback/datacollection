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

char b[10100];
int mas[10100];
int dp[10100];

// encode: 
// 0  1  2  3  4  5  6  7
// 1  i  j  k -1 -i -j -k
int mp[8][8] = {
	{ 0, 1, 2, 3, 4, 5, 6, 7},
	{ 1, 4, 3, 6, 5, 0, 7, 2},
	{ 2, 7, 4, 1, 6, 3, 0, 5},
	{ 3, 2, 5, 4, 7, 6, 1, 0},
	{ 4, 5, 6, 7, 0, 1, 2, 3},
	{ 5, 0, 7, 2, 1, 4, 3, 6},
	{ 6, 3, 0, 5, 2, 7, 4, 1},
	{ 7, 6, 1, 0, 3, 2, 5, 4}
};

int toid(char c)
{
	int res = 0;
	switch (c)
	{
	case 'i': res++; break;
	case 'j': res += 2; break;
	case 'k': res += 3; break;
	}
	return res;
}

void Solve()
{
	int i, j, k, n, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		int l;
		ll x;
		scanf("%d %lld", &l, &x);
		in_str(b);
		string s(b), s1(b);
		for (i = 1; i < x; i++) s += s1;
		n = l * x;
		for (i = 0; i < n; i++) mas[i] = toid(s[i]);
		int last = 0;
		for (i = n - 1; i >= 0; i--)
		{
			dp[i] = mp[mas[i]][last];
			last = dp[i];
		}

		bool ok = false;
		last = 0;
		for (i = 0; i < n - 2; i++)
		{
			last = mp[last][mas[i]];
			if (last == 1)
			{
				int llast = 0;
				for (j = i + 1; j < n - 1; j++)
				{
					llast = mp[llast][mas[j]];
					if (llast == 2 && dp[j + 1] == 3)
					{
						ok = true;
						break;
					}
				}
				if (ok) break;
			}
			if (ok) break;
		}

		printf("Case #%d: %s\n", test, ok ? "YES" : "NO");
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