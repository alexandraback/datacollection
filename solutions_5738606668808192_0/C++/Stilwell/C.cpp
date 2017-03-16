#include <stdio.h>
#include <stdlib.h>
using namespace std;

int N,J,i,j,k,len;
int a[10005],b[1005],c[10005];
long long x;

bool check(int base)
{
	int i,j,k;
	x=0;
	for(i=1;i<=len;++i)c[i]=0;
	for(i=1;i<=N;++i)
	{
		for(j=1;j<=len;++j)c[j]*=base;
		c[1]+=a[i];
		for(j=1;j<=len;++j)c[j+1]+=c[j]/10,c[j]%=10;
		x=x*base+a[i];if(x>1000)x=1000;
	}
	for(i=2;i<x;++i)
	{
		k=0;
		for(j=len;j>=1;--j)k=(k*10+c[j])%i;
		if(k==0)
		{
			b[base]=i;
			return true;
		}
	}
	return false;
}

void dfs(int x)
{
	if(x>=N)
	{
		for(i=2;i<=10;++i)
		if(!check(i))return;
		--J;
		for(i=1;i<=N;++i)printf("%d",a[i]);
		for(i=2;i<=10;++i)printf(" %d",b[i]);
		printf("\n");
		if(J==0)exit(0);
		return;
	}
	a[x]=0;dfs(x+1);
	a[x]=1;dfs(x+1);
}

int main()
{
	freopen("1.out","w",stdout);
	printf("Case #1:\n");
	N=16;J=50;len=50;
	a[1]=a[N]=1;
	dfs(2);
}
