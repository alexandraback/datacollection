#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[1234];
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int tcase = 1; tcase <= cases; ++tcase)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		int ans = 1000000000;
		for (int m = 1; m <= 1000; ++m)
		{
			int an = m;
			for (int i = 0; i < n; ++i)
			if (a[i] > m)
			{
				an += (a[i] / m) - 1;
				if (a[i] % m > 0)
					an++;
			}
			if (an < ans)
				ans = an;
		}
		printf("Case #%d: %d\n", tcase, ans);
	}
}
