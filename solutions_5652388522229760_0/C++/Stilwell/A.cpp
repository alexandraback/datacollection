#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,Case,n,i,j,k;
long long x;

int calc(long long x)
{
	int k=0;
	for(;x;x/=10)k|=1<<(x%10);
	return k;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d",&n);k=0;++Case;
		if(n==0)
		{
			printf("Case #%d: INSOMNIA\n",Case);
			continue;
		}
		for(i=1,x=n;k!=1023;++i,x+=n)k|=calc(x);
		printf("Case #%d: %I64d\n",Case,x-n);
	}
}
