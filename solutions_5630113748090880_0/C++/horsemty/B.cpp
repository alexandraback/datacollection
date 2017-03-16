#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int T,a[5000],h,n;
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		int maxx=0;
		for(int i=1;i<=2*n-1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&h);
				a[h]++;
				if (h>maxx)
					maxx=h;
			}
		}
		printf("Case #%d:",t);
		for(int i=1;i<=maxx;i++)
			if (a[i]%2)
				printf(" %d",i);
		printf("\n");		
	}
}
