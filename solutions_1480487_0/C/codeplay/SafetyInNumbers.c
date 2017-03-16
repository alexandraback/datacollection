#include<stdio.h>
int main()
{
	int t, ct=0;
	scanf("%d", &t);
	while(t--)
	{
		ct++;
		int n, i, initial, temp, count=0;
		scanf("%d", &n);
		scanf("%d", &initial);
		int diff[n];
		int sum =initial;
		// diff for x2 sits in diff[1]
		for(i=1; i<n; i++)
		{
			scanf("%d", &temp);
			diff[i]=initial-temp;
			sum += temp;
		}

		double ans, ans2[n], negsum=0, a;
		ans=(2.0*sum - n*initial)/(sum*n)*100;
		if(ans < 0)
		{
			count++;
			negsum+=ans;
			ans2[0]=0;
		}
		else
			ans2[0]=ans;
		for(i=1; i<n; i++)
		{
			a=ans+(diff[i]*100.0)/sum;
			if(a < 0)
			{
				count++;
				ans2[i]=0;
				negsum+=a;
			}
			else
				ans2[i]=a;	
		}
		if(count!=0)
		a=negsum/(n-count)*1.0;
		else
			a=0;
	//	printf("a=%lf\n", a);

		
		if(ans2[0] == 0)
		
			printf("Case #%d: 0.000000",ct);
		else
		printf("Case #%d: %lf",ct, ans2[0]+a);
		for(i=1; i<n; i++)
		{
			if(ans2[i]!=0)
				printf(" %.6lf", ans2[i]+a);
			else printf(" %.6lf", ans2[i]);
		}
		printf("\n");

	}
	return 0;
}
