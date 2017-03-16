#include <cstdio>
#include <cstring>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
	freopen("4in.txt", "r", stdin);
	freopen("4out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		int ret = 0;
		printf("Case #%d: ", cas);
		if (r * c % x || MAX(r, c) < x || r + c - 1 < x || MIN(r, c) < (x+1)/2 || x >= 7)
			ret = 1;
		if (MIN(r, c) == 2 && x >= 4)
			ret = 1;
		if (ret == 1)
		{
			puts("RICHARD");
			continue;
		}
		if (x < 5 || MIN(r, c) >= x)
		{
			puts("GABRIEL");
			continue;
		}
		if (MIN(r, c) <= 3 || r * c / x <= 2)
			ret = 1;
		if (MIN(r, c) >= 4) ret = 0;
		
		if (ret == 1)
		{
			puts("RICHARD");
			continue;
		}
		puts("GABRIEL");
		continue;

	}
	return 0;
}
