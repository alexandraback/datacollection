#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define INF 0x0a0a0a0a

long long twos[50];

int dfs(long long x, long long y)
{
	if (x == 0) return INF;
	if (x == y) return 0;
	while (x % 2 == 0)
	{
		x /= 2;
		y /= 2;
	}
	int a = dfs(x - 1, y);
	int b = dfs(x + 1, y);
	return min(a, b) + 1;
}

int main()
{
	long long p, q;
	int t, cas;
	int i;
	twos[0] = 1;
	for (i = 1; i < 50; i++)
		twos[i] = 2 * twos[i - 1];
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		char c;
		printf("Case #%d: ", cas);
		cin >> p >> c >> q;
		if (q % p == 0)
		{
			q /= p;
			p = 1;
		}
		// cout << p << "/" << q << endl;
		for (i = 0; i < 50; i++)
			if (twos[i] == q)
				break;
		if (i == 50) printf("impossible\n");
		else
		{
			for (i = 0; i < 50; i++)
				if (twos[i] * p >= q)
					break;
			printf("%d\n", i);
		}
	}
	return 0;
}
