#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int T,tc;
int k,c,s;
__int64 p;

int main()
{
	int i,j,u;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	for(scanf("%d",&T),tc=1;tc<=T;++tc)
	{
		scanf("%d%d%d",&k,&c,&s);
		if(c*s<k)
		{
			printf("Case #%d: IMPOSSIBLE\n",tc);
			continue;
		}
		printf("Case #%d: ",tc);
		u=0;
		for(i=1;u<k;++i)
		{
			p=0;
			for(j=0;j<c;++j)
			{
				++u;
				p=p*k+(u>=k?0:u);
			}
			++p;
			printf("%I64d ",p);
		}
		printf("\n");
	}
	return 0;
}