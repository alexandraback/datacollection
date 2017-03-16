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
#define INF 2000000000

char al[110];
char word[110];
int s, k, l;
char w[110];
double p;
double ans;
int mx;

int calc()
{
	int i, j;
	int res = 0;

	for (i = 0; i < s; i++)
	{
		for (j = 0; j+i < s && j < l && w[i+j] == word[j]; j++);
		res += j == l;
	}

	return res;
}

void doit(int pos)
{
	if (pos == s)
	{
		int ret = calc();
		mx = max(mx, ret);
		ans += ret;
		return;
	}
	for (int i = 0; i < k; i++)
	{
		w[pos] = al[i];
		doit(pos + 1);
	}
}

void Solve()
{
	int i, j, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		in_int3(k, l, s);
		in_str(al);
		in_str(word);
		p = 1.0 / pow(0.0+k, 0.0+s);
		mx = 0;
		ans = 0.0;
		doit(0);
		ans /= pow(0.0 + k, 0.0 + s);
		printf("Case #%d: %.10lf\n", test, mx - ans);
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