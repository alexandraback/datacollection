#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#include "memory.h"

int t;

long long b,m;

int bin[100];

int len;

int main()
{
	int i,j,k;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%lld %lld",&b,&m);
		memset(bin,0,sizeof(bin));
		len = 0;
		m --;
		while (m>0)
		{
			bin[len] = m%2;
			m /= 2;
			len ++;
		}
		if (len > b-2)
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		printf("Case #%d: POSSIBLE\n",i+1);
		for (j=b-2;j>=0;j--)
		{
			printf("%d",bin[j]);
		}
		printf("1");
		printf("\n");
		for (j=1;j<b;j++)
		{
			for (k=0;k<b;k++)
			{
				if (k <= j)
				{
					printf("0");
				}
				else
				{
					printf("1");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
