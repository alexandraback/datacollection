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

int mas[128];
char b[2010];

string num[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

void dec(int n, int v)
{
	for (int i = 0; i < num[n].size(); i++) mas[num[n][i]] -= v;
}

void Solve()
{
	int i, j, k, n, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests;test++)
	{
		mset(mas, 0);
		in_str(b);
		for (i = 0; b[i]; i++)mas[b[i]]++;
		vector<int> ans(10, 0);

		// 0
		ans[0] = mas['Z'];
		dec(0, ans[0]);

		// 2
		ans[2] = mas['W'];
		dec(2, ans[2]);

		// 4
		ans[4] = mas['U'];
		dec(4, ans[4]);

		// 1
		ans[1] = mas['O'];
		dec(1, ans[1]);

		// 3
		ans[3] = mas['R'];
		dec(3, ans[3]);

		// 5
		ans[5] = mas['F'];
		dec(5, ans[5]);

		// 6
		ans[6] = mas['X'];
		dec(6, ans[6]);

		// 7
		ans[7] = mas['S'];
		dec(7, ans[7]);

		// 8
		ans[8] = mas['G'];
		dec(8, ans[8]);

		// 9
		ans[9] = mas['N'] / 2;
		dec(9, mas['N']);

		printf("Case #%d: ", test);
		for (i = 0; i < 10; i++)
		{
			for (j=0;j<ans[i];j++) printf("%d", i);
		}

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