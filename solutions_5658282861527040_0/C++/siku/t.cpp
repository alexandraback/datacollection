#include<stdio.h>
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("2.txt","w",stdout);
	int a,b,k,t,i,j,tt=0,x;
	long long c=0;
	scanf("%d",&t);
	while(t--)
	{
		tt++;
		c=0;
		scanf("%d %d %d",&a,&b,&k);
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
			{
				x=i&j;
				if(x<k)
				c++;
			}
		printf("Case #%d: %lld\n",tt,c);
	}
	return 0;
}
