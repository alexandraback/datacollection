#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int csnum;
	int cs;

	scanf ("%d", &csnum);
	for (cs = 1; cs <= csnum; cs++)
	{
		scanf ("%d %d", &a, &b);

		int ret = 0;
		for (int i = a; i < b; i++)
		{
			int k = i;
			int t, x;
			int cnt = 0;
			for (x = 1; x <= k; x *= 10)
				cnt++;

		//	printf ("cnt=%d\n", cnt);

			for (int d = 10; d <= k; d *= 10)
			{
				x /= 10;
				t = k / d + (k % d) * x;	
				if (t <= b && t > k)
					ret++;
			}
		}

		printf ("Case #%d: %d\n", cs, ret);
	}

	return 0;
}
