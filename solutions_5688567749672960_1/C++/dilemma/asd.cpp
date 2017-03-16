#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef long long LL;
LL a[30];
int b[30];
LL ten[30];
int main(void)
{
	int i,j,u,m,pi,qi;
	LL p,q,n,sum,sump1,sump2;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	ten[1]=1;
	for(i=2;i<=17;i++)
	{
		ten[i]=10*ten[i-1];
	}
	a[1]=1;
	a[2]=10;
	for(i=3;i<=16;i++)
	{
		if(i%2==0)
		{
			u=(i-1)/2;
			a[i]=a[i-1]+ten[u+1]+ten[u+2]-1;
		}
		else
		{
			u=i/2;
			a[i]=a[i-1]+ten[u+1]+ten[u+1]-1;
		}
	}
	scanf("%d",&pi);
	for(qi=1;qi<=pi;qi++)
	{
		scanf("%lld",&n);
		p=1;
		m=1;
		while(p<=n)
		{
			m++;
			p=p*10;
		}
		m--;
		p/=10;
		sum=a[m]+n-p;
		if(p==n)
		{
			printf("Case #%d: %lld\n",qi,sum);
		}
		else
		{
			q=n;
			for(i=1;i<=m;i++)
			{
				b[m-i+1]=q%10;
				q/=10;
			}
			if(b[m]==1)
			{
				sump1=0;
				for(j=m-1;j>=1;j--)
				{
					sump1=10*sump1+b[j];
				}
				if(a[m]+sump1+1<sum)
				{
					sum=a[m]+sump1+1;
				}
			}
			for(i=1;i<m;i++)
			{
				sump1=sump2=0;
				for(j=i;j>=1;j--)
				{
					sump1=10*sump1+b[j];
				}
				for(j=i+1;j<=m;j++)
				{
					sump2=10*sump2+b[j];
				}
				if(a[m]+sump1+sump2<sum)
				{
					sum=a[m]+sump1+sump2;
				}
			}
			printf("Case #%d: %lld\n",qi,sum);
		}
	}
	return 0;
}