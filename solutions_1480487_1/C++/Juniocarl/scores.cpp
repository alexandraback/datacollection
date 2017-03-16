#include <stdio.h>

int main()
{	
	int t;
	scanf("%d",&t);
	
	for(int caso=1;caso<=t;caso++)
	{
		int n;
		int score[500];
		int sum = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&score[i]);
			sum += score[i];
		}
		
		double S = double(2 * sum) / n;
		printf("Case #%d: ",caso);
		double ans[500];
		double otherSum = 0.0;
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			ans[i] = 100*(S - score[i])/sum;
			if ( ans[i] <= 0.0 )
			{
				otherSum += ans[i];
				cnt++;
				ans[i] = 0.0;
			}			
		}	
		for(int i=0;i<n;i++)
		{
			if ( ans[i] != 0 && cnt != 0)
			{
				ans[i] += otherSum/(n-cnt);
			}
			printf("%.6lf ",ans[i]);
		}		
		printf("\n");
	}
	return 0;
}