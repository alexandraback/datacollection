#include <cstdio>
#include <set>

using namespace std;

int t, cases;

int lng(int n)
{
	if (n < 10) return 1;
	if (n < 100) return 10;
	if (n < 1000) return 100;
	if (n < 10000) return 1000;
}

int solve(int n, int m)
{
	set<pair<int, int> > s;

	for (int i = n; i <= m; ++i)
	{
		int p, lngi;
		if (n < 10) continue;
		if (n < 100)
			lngi = p = lng(i);
		else if (n < 1000)
			lngi = p = lng(i);
		else if (n < 10000)
			lngi = p = lng(i);

		int t = 10;
		while (i / t > 0)
		{
			int x = (i % t)	* p + i / t;
			t *= 10; p /= 10;
			
			if (lngi == lng(x) && x != i && n <= x && x <= m)
			{
				int y;
				if (x < i)
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

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("Case #%d: %d\n", ++cases, solve(n, m));
	}
}