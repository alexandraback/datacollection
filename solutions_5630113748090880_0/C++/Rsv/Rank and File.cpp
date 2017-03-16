#include <stdio.h>
#include<string.h>
#include<algorithm>
int main()
{
	using namespace std;
	freopen( "B-small-attempt1.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int n,t,i,sum,rsv,lol,len,x,rv[51],j;
	bool a[2501];
	scanf("%d",&t);
	for(lol=1;lol<=t;lol++)
	{
		for(i=0;i<2501;i++)
		{
			a[i]=true;
		}
		scanf("%d",&n);
		rsv=(2*n)-1;
		for(i=0;i<rsv;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			if(a[x]==true)
			a[x]=false;
			else
			a[x]=true;
//			a[x]=!a[x];
		}
		
		for(i=0,j=0;i<2501;i++)
		{
			if(a[i]==false)
			{
				rv[j]=i;
			j++;
			}
		}
//		if(j<=n)printf("sfgdak");
		printf("Case #%d:",lol);
		sort(rv,rv+n);
		for(i=0;i<n;i++)
		printf(" %d",rv[i]);
		
		printf("\n");
	}
	return 0;
}
		
