#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	int d;
	int i, j;
	int *pan;
	int max;
	int num;
	int time;

	scanf("%d", &t);

	for (i = 1; i <= t; i++)
	{
		scanf("%d", &d);

		max = 0;

		//pan = malloc(sizeof(int)*d);

		for (j = 0; j < d; j++)
		{
			scanf("%d", &num);
			if (max < num)
				max = num;
		}

		if (max < 4)
			time = max;
		else if (max == 4)
			time = 3;
		else if (max > 4 && max < 9)
			time = 4;
		else
			time = 5;

		printf("Case #%d: %d", i, time);
	}

	return 0;
}