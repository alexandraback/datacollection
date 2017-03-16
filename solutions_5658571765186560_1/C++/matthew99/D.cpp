#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	static int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case)
	{
		printf("Case #%d: ", Case);
		static int x, n, m;
		scanf("%d%d%d", &x, &n, &m);
		if ((n * m) % x) printf("RICHARD\n"); 
		else
		{
			if (x <= 2) printf("GABRIEL\n");
			else
			{
				if (n > m) swap(n, m);
				if (x == 3)
				{
					if (n == 1) printf("RICHARD\n");
					else printf("GABRIEL\n");
				}
				if (x == 4)
				{
					if (n <= 2) printf("RICHARD\n");
					else printf("GABRIEL\n");
				}
				if (x == 5)
				{
					if (n <= 3) printf("RICHARD\n");
					else printf("GABRIEL\n");
				}
				if (x == 6)
				{
					if (n <= 4) printf("RICHARD\n");
					else printf("GABRIEL\n");
				}
				if (x > 6) printf("GABRIEL\n");
			}
		}
	}
	return 0;
}
