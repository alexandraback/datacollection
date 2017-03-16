#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main (void)
{
	int T;

	scanf ("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int a[10] = {0, }, cnt = 10;
		long long x, i;

		scanf ("%lld", &x);

		if (x == 0) { printf ("Case #%d: INSOMNIA\n", t); continue; }

		for (i = 1; cnt; i++)
		{
			long long y = i*x;

			while (y)
			{
				if (!a[y%10])
				{
					a[y%10]++;
					cnt--;
				}
				y /= 10;
			}
		}

		printf ("Case #%d: %lld\n", t, x*--i);
	}
}