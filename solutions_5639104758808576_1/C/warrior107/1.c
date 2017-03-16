#include<stdio.h>

int main()
{
	int t;
	char aud[100];
	int smax;
	int i,j;
	int total;
	int more;

	scanf("%d", &t);

	for (j = 1; j <= t;j++)
	{
		scanf("%d", &smax);
		scanf("%s", aud);

		total = 0;
		more = 0;

		for (i = 0; i <= smax; i++)
		{
			if (i > total)
			{
				more = more + i - total;
				total = i + aud[i] - 48;
			}
			else
			{
				total = total + aud[i] - 48;
			}
		}

		printf("Case #%d: %d\n", j, more);
	}

	getch();

	return 0;
}