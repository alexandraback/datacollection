#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int INF=1<<28;
int main(void)
{
	int u,v,p,n,m,pi,qi,sum;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&pi);
	for(qi=1;qi<=pi;qi++)
	{
		scanf("%d%d%d",&n,&m,&p);
		if(m==p)
		{
			sum=m;
		}
		else if(2*p-1>=m)
		{
			sum=p+1;
		}
		else
		{
			sum=0;
			u=2*p-1;
			v=m;
			while(u<v)
			{
				v=v-p;
				sum++;
			}
			if(v==p)
			{
				sum=sum+p;
			}
			else
			{
				sum=sum+p+1;
			}
		}
		sum=sum+(n-1)*(m/p);
		printf("Case #%d: %d\n",qi,sum);
	}
	return 0;
}