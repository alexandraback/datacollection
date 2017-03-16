#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,k,i;
	int n,s,p;
	int ans;
	int co=1;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&s,&p);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		ans=0;
		for (i=0;i<n;i++)
		{
			if ((a[i]+2)/3>=p)
				ans++;
			else
			{
				if (a[i]>=2&&s>0)
				{
					if (a[i]%3==0)
						k=a[i]/3+1;
					if (a[i]%3==1)
						k=a[i]/3+1;
					if (a[i]%3==2)
						k=a[i]/3+2;
					if (k>=p)
					{
						ans++;
						s--;
					}
				}
			}
		}
		printf("Case #%d: %d\n",co++,ans);
	}
	return 0;
}