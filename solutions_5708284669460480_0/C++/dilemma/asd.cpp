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
char a[20];
char b[20];
char c[20];
int main(void)
{
	int i,j,u,p,q,n,m,pi,qi,pp,sum,sump,maxp;
	bool OK;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&pi);
	for(qi=1;qi<=pi;qi++)
	{
		scanf("%d%d%d",&n,&m,&p);
		scanf("%s%s",a,b+1);
		pp=1;
		for(i=1;i<=p;i++)
		{
			pp=pp*n;
		}
		sum=maxp=0;
		for(i=0;i<pp;i++)
		{
			q=i;
			for(j=1;j<=p;j++)
			{
				c[j]=a[q%n];
				q/=n;
			}
			sump=0;
			for(u=1;u<=p-m+1;u++)
			{
				OK=true;
				for(j=1;j<=m;j++)
				{
					if(b[j]!=c[j+u-1])
					{
						OK=false;
						break;
					}
				}
				if(OK==true)
				{
					sump++;
				}
			}
			maxp=sump>maxp?sump:maxp;
			sum=sum+sump;
		}
		printf("Case #%d: %.6f\n",qi,maxp-(double)sum/pp);
	}
	return 0;
}