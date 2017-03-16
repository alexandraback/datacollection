#include <stdio.h>
#include<algorithm>
using namespace std;
double a[1005],b[1005];
int n,t,win,first,last;
int main(int argc, char *argv[])
{
	scanf("%d",&t);
	for(int r=1;r<=t;r++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&b[i]);
		}
		sort(&a[0],&a[n]);
		sort(&b[0],&b[n]);
		first=0;
		last=n-1;
		win=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>b[first])
			{
				win++;
				first++;
			}
			else
			{
				last--;
			}
		}
		printf("Case #%d: ",r);
		printf("%d ",win);
		first=0;
		last=n-1;
		win=0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]>b[last])
			{
				win++;
				first++;
			}
			else
			{
				last--;
			}
		}
		printf("%d\n",win);
	}
	
	return 0;
}
