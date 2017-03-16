#include <stdio.h>
#include <stdlib.h>

int contestants[300];

int main()
{
	int t, n, j, x, i, sum, diff, cnt, s1 ,s2;
	double temp, var, neg_sum;
	scanf("%d", &t);
	x = 0;
	while (t)
	{
		t--;
		x++;
		printf("Case #%d: ",x);
		scanf("%d",&n);
		sum = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&contestants[i]);
			sum += contestants[i];
		}
		cnt = 0;
		diff = 2 * sum ;
		temp = ((double)diff)/((double)n);
		neg_sum = 0;
		for (i = 0; i < n; ++i)
		{
			var = 100*(temp - contestants[i])/sum;
			if(var < 0)
			{
				neg_sum -= var;
				cnt++;
			}
		}
		if (cnt > 0)
			neg_sum = neg_sum / (n-cnt);
		for (i = 0; i< n; ++i)
		{
			var = 100*(temp - contestants[i])/sum;
			var -= neg_sum;
			if (var < 0)
				printf("0.000000 ");
			else
				printf("%.6f ",var);
		}
		printf("\n");

	}
	return 0;
}
