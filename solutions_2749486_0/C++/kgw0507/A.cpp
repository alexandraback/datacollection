#include <stdio.h>

int TC,tc;
int x,y;

int main()
{
	int i;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	for(scanf("%d",&TC),tc=1;tc<=TC;++tc)
	{
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",tc);
		if(x<0)
			for(i=1;i<=-x;++i)
				printf("EW");
		else 
			for(i=1;i<=x;++i)
				printf("WE");
		if(y<0)
			for(i=1;i<=-y;++i)
				printf("NS");
		else 
			for(i=1;i<=y;++i)
				printf("SN");
		printf("\n");
	}
	return 0;
}