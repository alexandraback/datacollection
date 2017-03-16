#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	for (int nc = 1; nc <= t; nc++)
	{
		int n, s, p;
		scanf("%d%d%d", &n, &s, &p);
		int total = 0;
		for (int i = 0; i < n; i++)
		{
			int score;
			scanf("%d", &score);
			int remain = score - p;
			if (remain >= 0)
			{
				// much higher
				if (remain / 2 >= p)
				{
					total++;
				}
				else if (remain - (p - 1) >= p - 1) // non-surprising
				{
					total++;
				}
				else if (remain - (p - 2) >= p - 2 && s > 0)
				{
					s--;
					total++;
				}
			}
		}

		printf("Case #%d: %d\n", nc, total);
	}

	return 0;
}
