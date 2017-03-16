#include <cstdio>

void test(int testNum)
{
	int n, p, s;
	scanf("%d%d%d", &n, &s, &p);

	int scores, count = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &scores);
		int div = scores / 3;
		int rem = scores % 3;
		if (div >= p)
			count++;
		else if(rem > 0 && div+1 == p)
		{
			count++;
		}
		else if (((rem == 0 && div + 1 == p && div - 1 >= 0) || (rem == 2 && div + 2 == p)) && s > 0)
		{
			count++;
			s--;
		}
	}

	printf("Case #%d: %d\n", testNum, count);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		test(i+1);
	}

	return 0;
}