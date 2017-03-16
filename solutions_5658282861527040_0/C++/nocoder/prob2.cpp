#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen ("input.in","r",stdin);
	freopen ("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int z;
	for (z=1;z<=t;z++)
	{
		printf("Case #%d: ",z);
		int a,b,k;
		scanf ("%d %d %d",&a,&b,&k);
		int i,j,g,count=0;
		for (i=0;i<a;i++)
		{
			for (j=0;j<b;j++)
			{
				g=i&j;
				if (g<k)
					count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}