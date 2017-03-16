#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
#include <bitset>
using namespace std;
int k, c, s;
long long powers[105];

long long checkPosition(int toCheck, int level)
{
	if ((level == 0) || (toCheck > k))
		return 1;
	return powers[level - 1] * (toCheck - 1) + checkPosition(toCheck + 1, level - 1);
}

int main()
{
	int test;
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d %d\n", &k, &c, &s);
		if (c * s < k)
		{
			printf("Case #%d: IMPOSSIBLE\n", t);
			continue;
		}
		powers[0] = 1;
		for (int i = 1; i <= c; i++)
			powers[i] = powers[i - 1] * k;
		int toCheck = 1;
		printf("Case #%d:", t);
		for (int i = 1; (i <= k) && (toCheck <= k); i++)
		{
			printf(" %llu", checkPosition(toCheck,c));
			toCheck += c;
		}
		printf("\n");

	}
	return 0;
}