#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long lint;
typedef unsigned long long ull;

#define pb push_back
#define mp make_pair

void solve(int testNumber)
{
	lint n, c, s;
	scanf("%lld%lld%lld", &n, &c, &s);

	lint need = n / c;
	if (n % c != 0) need++;

	if (need > s)
	{
		printf("IMPOSSIBLE\n");
		return;
	}

	lint pos = 0;
	for (lint i = 0; i < need; i++)
	{
		lint val = 0;
		for (lint j = 0; j < c; j++)
		{
			val = n * val + pos;
			pos++;
			if (pos == n) pos = n - 1;
		}

		printf("%lld ", val + 1);
	}

	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	scanf("%d", &tn);
	for (int i = 0; i < tn; i++)
	{
		printf("Case #%d: ", i + 1);
		solve(i + 1);
	}
}
