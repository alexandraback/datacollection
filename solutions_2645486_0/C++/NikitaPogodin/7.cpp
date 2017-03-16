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

int t, e, r, n;
int v[100] = {};
int Max = 0;

void Go(int cur, int curE, int gain)
{
	if (cur >= n)
	{
		Max = max(Max, gain);
		return;
	}
	curE = min(curE + r, e);
	for (int j = 0; j <= curE; j++)
		Go(cur + 1, curE - j, gain + v[cur]*j);
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d%d", &e, &r, &n);
		Max = 0;
		for (int j = 0; j < n; j++)
			scanf("%d", &v[j]);
		Go(0, e, 0);
		printf("Case #%d: %d\n", i + 1, Max);
	}
	return 0;
}