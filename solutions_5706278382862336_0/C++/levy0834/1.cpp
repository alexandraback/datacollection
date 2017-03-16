#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <set>
using namespace std;

#pragma comment(linker, "/STACK:36777216")

#define INF 0x7fffffff
#define EPS 1e-8

typedef long long LL;

LL gcd(LL a, LL b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, cs;
	scanf("%d", &T);
	for (cs = 1; cs <= T; ++cs)
	{
		LL p, q;
		scanf("%lld/%lld", &p, &q);
		LL g = gcd(p, q);
		p /= g;
		q /= g;
		int n = 0;
		int ans = -1;
		while (q % 2 == 0)
		{
			q /= 2;
			n++;
			if (ans == -1 && p >= q)
			{
				ans = n;
			}
		}
		printf("Case #%d: ", cs);
		if (q != 1)
		{
			printf("impossible\n");
			continue;
		}
		printf("%d\n", ans);
	}
}