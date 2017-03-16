#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int i,j,n,m,t,k,x,y,a,b,ans,p;
	scanf("%d",&t);
	for(p=1;p<=t;p++)
	{
		ans=0;
		scanf("%d%d%d",&a,&b,&k);
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				if((i&j) < k)	ans++;
			}
		}
		printf("Case #%d: %d\n",p,ans);
	}
	return 0;
}
