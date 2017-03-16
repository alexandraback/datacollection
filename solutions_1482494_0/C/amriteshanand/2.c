#include<stdio.h>
#include<string.h>
#include<stdlib.h>
solve()
{
	int n,i,j,k,count,y,max,hh;
	int s[100][2];
	int v;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{scanf("%d%d",&s[i][0],&s[i][1]);}
	count=0;hh=0;max=0;
	while(1)
	{
		v=0;y=0;
		if(count==n)break;
		for(i=0;i<n;i++)
		{
			if(s[i][1]<=max)
			{if(s[i][0]<90000)v=2;else v=1;count++;s[i][1]=100000;y=1;hh++;/*printf("%d\n",s[i][1]);*/goto l1;}
		}
		for(i=n-1;i>0;i--)
		{
			if(s[i][0]<=max)
			{v=1;s[i][0]=120000;y=1;hh++;break;}
		}
l1:		max+=v;	
		if(y==0)
		{printf("Too Bad\n");return 0;}	
	}
	printf("%d\n",hh);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
