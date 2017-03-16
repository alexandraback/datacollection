#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int T,tc;
int n,m;
__int64 o,div[11];

int main()
{
	int i,j,k,u;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	for(scanf("%d",&T),tc=1;tc<=T;++tc)
	{
		scanf("%d%d",&n,&m);
		printf("Case #%d:\n",tc);
		for(i=2;i<=10;++i)
		{
			o=1;
			for(j=1;j<=n/2;++j)
				o*=i;
			o++;
			for(j=2;j*j<=o && (o%j);++j);
			div[i]=(j*j>o?o:j);
		}
		for(i=0;i<m;++i)
		{
			for(k=0;k<=1;++k)
			{
				printf("1");
				for(u=i,j=1;j<n/2-1;++j,u/=2)
					printf("%d",u%2);
				printf("1");
			}
			for(j=2;j<=10;++j)
				printf(" %I64d",div[j]);
			printf("\n");
		}
	}
	return 0;
}