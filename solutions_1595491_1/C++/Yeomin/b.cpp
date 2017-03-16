#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n, s, p;
int table[100];

int solve()
{
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		int m = table[i] / 3;
		int t1, t2, t3;
		t1 = m; t2 = m; t3 = m;
		if (m * 3 < table[i])
		{
			t3++;
			if (m * 3 + 2 == table[i])
				t2++;
		}

		if (t3 >= p)
			++ret;
		else if (t3 + 1 == p && s > 0)
		{
			if (t2 > 0 && t2 == t3)
			{
				--t2; ++t3;
				++ret; --s;
			}
		}
//		printf("triplet: (%d, %d, %d) - %d\n", t1, t2, t3, t1 + t2 + t3);
	}

	return ret;
}

int main()
{
	int t, cases = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i < n; ++i)
			scanf("%d", &table[i]);
		sort(table, table + n, greater<int>());

		printf("Case #%d: %d\n", ++cases, solve());
	}
}