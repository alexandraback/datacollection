#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "memory.h"

int t;

int a,b,c;

int n;

int main()
{
	int i,j,k,l;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&n);
		if (n>=c)
		{
			printf("Case #%d: %d\n",i+1,a*b*c);
			for (j=1;j<=a;j++)
			{
				for (k=1;k<=b;k++)
				{
					for (l=1;l<=c;l++)
					{
						printf("%d %d %d\n",j,k,l);
					}
				}
			}	
			continue;
		}
		printf("Case #%d: %d\n",i+1,a*b*n);
		for (j=1;j<=a;j++)
		{
			for (k=1;k<=b;k++)
			{
				for (l=1;l<=n;l++)
				{
					int x = ((j+k-2+l)-1)%c+1;
					printf("%d %d %d\n",j,k,x);
				}
			}
		}
	}
	return 0;
}
