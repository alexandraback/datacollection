
#include <stdio.h>
#include <math.h>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test,T,i;
	scanf("%d",&test);
	T=test;
	while(test--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",T-test);
		for(i=0;i<fabs(x);i++)
		{
			if(x>=0)
			{
				printf("WE");
			}
			else printf("EW");
		}
		for(i=0;i<fabs(y);i++)
		{
			if(y>=0)
			{
				printf("SN");
			}
			else printf("NS");
		}
		printf("\n");
	}
	return 0;
}
