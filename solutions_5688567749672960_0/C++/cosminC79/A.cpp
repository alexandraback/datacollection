#include <cstdio>
#define NMAX 1000505
int best[NMAX], tests;

inline int rev(int x)
{
	int res = 0;
	while (x)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	
	return res;
}

inline int ndigits(int x)
{
	if (x == 0)
		return 0;
	int res = 0;
	while (x)
	{
		res++;
		x /= 10;
	}
	return res;
}

inline int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	best[1] = 1;
	for (int i = 2; i < NMAX; i++)
	{
		best[i] = best[i - 1] + 1;
		int x = rev(i);
		
		if (x < i && ndigits(x) == ndigits(i))
			best[i] = min(best[i], best[x] + 1);
	}
	
	scanf("%d", &tests);
	for (int test_no = 1; test_no <= tests; test_no++)
	{
		int no;
		scanf("%d", &no);
		
		printf("Case #%d: %d\n", test_no, best[no]);
	}
	return 0;
}
