#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100];
int main()
{
	int tt,t,s,n,p,i,j,x;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d %d %d",&n,&s,&p);
		for (i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		x=0;
		for (i=n-1;i>=0;i--)
		{
			if (p+(p-1)+(p-1)<=a[i])
				x++;
			else if (p>=2&&p+(p-2)+(p-2)<=a[i]&&s>0)
			{
				s--;
				x++;
			}
		}
		printf("Case #%d: %d\n",tt,x);
	}
	return 0;
}
