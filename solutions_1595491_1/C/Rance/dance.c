#include <stdio.h>

int main()
{
	int tcnt, gcnt, scnt, ocnt;
	int max, trimax;
	int g[100];
	scanf("%d\n", &tcnt);

	for (int i = 1; i <= tcnt; i++)
	{
		scanf("%d %d %d\n", &gcnt, &scnt, &max);
		trimax = 3*max;

		for (int j = 0; j < gcnt; j++)
			scanf("%d\n", &g[j]);

		ocnt = 0;

		for (int j = 0; j < gcnt; j++)
		{
			if (g[j] > trimax - 3)
				ocnt++;
			else if (scnt > 0)
			{
				if (max - 2 >= 0 &&
				   (g[j] == trimax - 3 || g[j] == trimax - 4))
				{
					scnt--;
					ocnt++;
				}
			}
		}

		printf("Case #%d: %d\n", i, ocnt);
	}

	return 0;
}
