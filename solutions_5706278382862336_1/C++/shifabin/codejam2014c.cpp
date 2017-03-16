#include<iostream>
#include<stdio.h>
using namespace std;
__int64 a[100];
__int64 gcd(__int64 x,__int64 y)
{
	if (x%y==0)  return y;
	return gcd(y,x%y);
}
bool _find(__int64 x)
{
	int i;
	for(i=0;i<=40;i++)
		if (x==a[i])  return true;
	return false;
}
int main()
{
	int ii,tt,i,u;
	__int64 p,n,m,tot;
	char x;
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&tt);
	a[0]=1;
	for(i=1;i<=60;i++)
		a[i]=a[i-1]*2;
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%I64d",&n);
		scanf("%c",&x);
		scanf("%I64d",&m);
		p=gcd(n,m);
		n=n/p;
		m=m/p;
		if (!_find(m)) {printf("Case #%d: impossible\n",ii);}
		else
		{
			tot=0;u=100;
			for(i=1;i<=40;i++)
			{
				if (tot+m/a[i]>n) continue;
				if (tot+m/a[i]==n) {
					if (u==100) u=i;
					tot=tot+m/a[i];
					break;
				}
				if (tot+m/a[i]<n)  
				{
					if (u==100) u=i;
					tot=tot+m/a[i];
				}
			}
			if (tot==n) printf("Case #%d: %d\n",ii,u);
			else
				printf("Case #%d: impossible\n",ii);
		}
	}
	return 0;
}