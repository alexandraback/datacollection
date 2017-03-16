#include <cstdio>
#include <set>

using namespace std;

int t, cases;
set<pair<int, int> > s;

int lng(int n)
{
	if (n < 10) return 1;
	if (n < 100) return 10;
	if (n < 1000) return 100;
	if (n < 10000) return 1000;
	if (n < 100000) return 10000;
	if (n < 1000000) return 100000;
	if (n < 10000000) return 1000000;
}

int solve(int n, int m)
{
	for (int i = n; i <= m; ++i)
	{
		int p, lngi;
		if (i < 10) continue;
		lngi = p = lng(i);

		int t = 10;
		while (i / t > 0)
		{
			int x = (i % t)	* p + i / t;
			t *= 10; p /= 10;
			
			if (lngi == lng(x) && x != i && n <= x && x <= m)
			{
				int y;
				if (x > i)
				{
					y = x; x = i;
				}
				else
				{
					y = i;
				}
				s.insert(make_pair(x, y));
			}
		}
	}

	return s.size();
}

int solve2(int n, int m)
{
	int ret = 0;
	for (set<pair<int, int>>::iterator it = s.begin(); it != s.end(); ++it)
	{
		if (n <= it->first && it->second <= m)
		{
			++ret;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &t);
	solve(1, 2000000);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("Case #%d: %d\n", ++cases, solve2(n, m));
	}
}