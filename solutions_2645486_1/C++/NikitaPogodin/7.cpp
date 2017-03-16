#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <memory.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <ctime>
#include <assert.h>

#define FOR(i, n) for (int i = 0; i < n; i++)

#pragma comment(linker, "/STACK:250777216")

using namespace std;

typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
const int MOD = int(1e9) + 7;
const int HMOD = (1 << 22) - 1;
const double eps = 1e-8;

const int N = 1000*1000*1000;

LL t, e, r, n;
LL v[11000] = {};
LL mySt[11000] = {};
LL near[11000] = {};
LL h = 0;

int main()
{
	freopen("b-large.in", "r", stdin);
	freopen("a2.out", "w", stdout);
	scanf("%I64d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%I64d%I64d%I64d", &e, &r, &n);
		memset(near, -1, sizeof(near));
		h = 0;
		for (int j = 0; j < n; j++)
			scanf("%I64d", &v[j]);
		for (int j = n - 1; j >= 0; j--)
		{
			while (h > 0 && v[j] > v[mySt[h - 1]])
				h--;
			if (h > 0)
				near[j] = mySt[h - 1];
			mySt[h++] = j;
		}
		LL curE = e;
		LL gain = 0;
		for (int j = 0; j < n; j++)
		{
			curE = min(e, curE + r);
			if (near[j] == -1)
			{
				gain += curE*v[j];
				curE = 0;
			}
			else
			{
				LL x = max(0ll, curE + (near[j] - j)*r - e);
				gain += min(curE, x)*v[j];
				curE -= min(curE, x);
			}
		}
		printf("Case #%d: %I64d\n", i + 1, gain);
	}
	return 0;
}