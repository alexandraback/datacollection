#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int nt;

long long gcd(long long a, long long b)
{
	while(a && b) if (a < b) b %= a; else a %= b;
	return a + b;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		long long p, q, g;

		scanf("%lld/%lld", &p, &q);

		g = gcd(p, q);

		p /= g; q /= g;

		long long was_q = q;
		int cnt = 0;
		bool ok = true;
		while(q > 1)
		{
			if (cnt > 40) { ok = false; break; }
			if (q % 2 != 0) { ok = false; break; }
			q /= 2;
			cnt++;
		}

		int res = 0;
		if (cnt > 40) ok = false;
		else
		{
			p *= (1LL << 40) / was_q;
			res = 40;
			while(p > 1)
			{
				res--;
				p /= 2;
			}
		}

		if (ok) printf("%d\n", res); else puts("impossible");
	}
	return 0;
}