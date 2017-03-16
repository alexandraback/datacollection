#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int T,tc;
__int64 n,m,o;
int c[10],see;

int main()
{
	int i;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	for(scanf("%d",&T),tc=1;tc<=T;++tc)
	{
		scanf("%I64d",&n);
		if(n==0)
		{
			printf("Case #%d: INSOMNIA\n",tc);
			continue;
		}
		see=0;
		for(i=0;i<10;++i)
			c[i]=0;
		for(m=n;;m+=n)
		{
			for(o=m;o;o/=10)
				if(!c[o%10])
					c[o%10]=1,++see;
			if(see==10)
				break;
		}
		printf("Case #%d: %I64d\n",tc,m);
	}
	return 0;
}