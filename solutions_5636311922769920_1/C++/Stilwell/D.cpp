#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,Case,K,C,S,n,i,j,k;
long long a[10005],b;

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d%d",&K,&C,&S);
		++Case;printf("Case #%d:",Case);
		n=0;k=0;
		for(;k!=K;)
		{
			b=++k;
			for(i=2;i<=C;++i)
			{
				++k;if(k>K)k=K;
				b=(b-1)*K+k;
			}
			a[++n]=b;
		}
		if(n<=S)
		{
			for(i=1;i<=n;++i)printf(" %I64d",a[i]);
			printf("\n");
		}else printf(" IMPOSSIBLE\n");
	}
}
