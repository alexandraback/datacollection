#include <stdio.h>

int main()
{
	int n, num, count;
	double aaa[300], sum, sumbig;
	bool bigger[300];
	double aver, averbig;
	
	freopen("A-small-attempt1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &num);
		sumbig = sum = count = 0;
		for (int j = 0; j < num; ++j)
		{
			scanf("%lf", &aaa[j]);
			sum += aaa[j];
		}
		aver = (double)sum*2/num;
		for (int j = 0; j < num; ++j)
		{
			if (aaa[j] > aver)
			{
				bigger[j] = true;
				sumbig += aaa[j];
			}
			else
			{
				bigger[j] = false;
				++count;
			}
		}
		averbig = (double)sumbig/count;
		for (int j = 0; j < num; ++j)
		{
			if (!bigger[j])
				aaa[j] += averbig;
		}
		printf("Case #%d:", i);
		for (int j = 0; j <num; ++j)
		{
			if (bigger[j])
				printf(" 0.000000");
			else
				printf(" %.6lf", (sum*2/count-aaa[j])/sum*100);
		}
		printf("\n");
	}
	return 0;
}
