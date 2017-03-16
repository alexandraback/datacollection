#include<iostream>
#include<cstdio>
#define maxn 10000
using namespace std;
int a[maxn];
int main()
{
	// freopen("input1.txt","r",stdin);
    freopen("B-small-attempt5.in","r",stdin);
   //freopen("B-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
	int t;
	scanf("%d",&t);
	
	for(int ti=1;ti<=t;ti++)
	{
		int max_x=0,n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			max_x=max(max_x,a[i]);
		}
		int ans=max_x;
		for(int i=1;i<=max_x;i++)
		{
			int cur=0,max2=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]>i)
				{
					cur += (a[j] / i)+((a[j]%i==0)?0:1)-1;
					max2=max(max2,i);
				}
				else max2=max(max2,a[j]);
			}
			cur+=max2;
			if(cur<ans)ans=cur;
		}
		printf("Case #%d: %d\n",ti,ans);
	}
	return 0;
}