#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,Case,n,i,j,k;
int a[10005];

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d",&n);
		for(i=1;i<=2500;++i)a[i]=0;
		for(i=1;i<=n+n-1;++i)
		for(j=1;j<=n;++j)
		scanf("%d",&k),a[k]^=1;
		++Case;
		printf("Case #%d:",Case);
		for(i=1;i<=2500;++i)if(a[i])printf(" %d",i);
		printf("\n");
	}
}
