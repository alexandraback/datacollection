#include <stdio.h>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,t1,i,j;
	double keep,enter,n,k,p,min;
	double a[10000];
	double back[10000];
	scanf("%d",&t);
	for(t1=1;t1<=t;t1++)
	{
		scanf("%lf %lf",&k,&n);
		p=1;
		back[(int)k] = 1;
		for(i=0;i<k;i++)
		{
			scanf("%lf",a+i);
			p*= a[i];
			back[(int)k-i-1] = p;
		}
		for(i=1;i<=k;i++)
		{
			back[i] = (n-k+1+i*2)*back[i] + (2*n-k+2+i*2)*(1-back[i]);
		}
		keep = p*(n-k+1)+(1-p)*(2*n-k+2);
		enter = n+2;
		min = keep;
		if(min>enter)
			min = enter;
		for(i=1;i<=k;i++)
		{
			if(min>back[i])
				min = back[i];
		}
		printf("Case #%d: %lf\n",t1,min);
	}
}