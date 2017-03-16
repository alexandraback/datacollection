#include <iostream>
#include <cstdio>

using namespace std;

double score[201], rate[201];

int main()
{
	freopen("A-small-attempt10.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int t;
	scanf("%d", &t);
	int i;
	for(i = 1; i <= t; i++)
	{
		int n;
		scanf("%d", &n);
		int j;
	    double sum = 0;
		for(j = 0; j < n; j++)
		{
			scanf("%lf", &score[j]);
			sum += score[j];
		}
		double ave = (double)1 / (double)n;
		double minus = 0;
		int count = 0;
		for(j = 0; j < n; j++)
		{
			rate[j] = score[j] / sum - ave;
		
			rate[j] = (ave - rate[j])*100;
			if(rate[j] < 0)
			{
				minus += -rate[j];
				rate[j] = 0;
			}
			else{
				++count;
			}
		}
		printf("Case #%d:", i);
		for(j = 0; j < n; j++)
		{
			printf(" %.6lf", rate[j] < 0.000001 ? rate[j] : rate[j] - minus/count);
		}
		printf("\n");
	}
	return 0;
}




