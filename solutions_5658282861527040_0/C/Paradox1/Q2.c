#include <stdio.h>

int main(void) {
	int a,b,c,t,i,k,j,count;


	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		count=0;
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		for(j=0;j<a;j++)
		{
			for(k=0;k<b;k++)
			{
                if((j&k) < c) count++;
                //printf("%d ",count);
            }

		}

		printf("Case #%d: %d\n",i+1,count);




	}
	return 0;
}
