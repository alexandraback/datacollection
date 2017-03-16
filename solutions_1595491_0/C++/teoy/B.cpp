#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[110];
int main(void)
{
	int T,S,p,N,g=0;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&S,&p);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&a[i]);
		}
		int sum=0;
		for(int i=1;i<=N;i++)
		{
			int max1,max2;
			if(a[i]%3==0)
			{
				if(a[i]!=0)
				{
					max1=min(10,a[i]/3);
					max2=min(10,a[i]/3+1);
				}
				else
				{
					max1=max2=0;
				}
			}
			else if(a[i]%3==1)
			{
				max1=min(10,a[i]/3+1);
				max2=min(10,a[i]/3+1);
			}
			else
			{
				max1=min(10,a[i]/3+1);
				max2=min(10,a[i]/3+2);
			}
			if(max1>=p) sum++;
			else if(max2>=p)
			{
				if(S>0)
				{
					S--;
					sum++;
				}
			}
		}
		printf("Case #%d: %d\n",++g,sum);
	}
	return  0;
}
