#include <stdio.h>

int main()
{
	int t,x,i,y,curx,cury,step,count;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",i);
		step=1; curx=cury=0;
		/*if(curx > x)
		{
			while(curx > x)
			{
				putchar('W');
				curx-=step;
				step++;
			}
			
		}
		if(cury > y)
		{
			while(cury > y)
			{
				putchar('S');
				curx-=step;
				step++;
			}
			
		}*/

		count=x-curx;
		if(count>0)
		{
			while(count--)
			{
				printf("WE");
			}
		}
		else
		{
			while(count++)
				printf("EW");
		}
		count=y-cury;
		if (count>0) 
		{
			while(count--)
			{
				printf("SN");
			}
		}
		else
		{
			while(count++)
				printf("NS");
		}
		
			// reached just below it. now move top right.

		printf("\n");

	}

	return 0;
}