#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int t,i,j,k,c,s;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d",&k,&c,&s);
		printf("Case #%d: ",i+1);
		for(j=0;j<s;j++)
		{
			printf("%d ",j+1);
		}
		printf("\n");
	}
	return 0;
}