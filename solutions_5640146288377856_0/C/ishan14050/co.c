#include<stdio.h>
int flag = 0;
int main()
{
	int t, r, c, w,i;
	scanf("%d",&t);
	for (i=1; i<=t; i++)
	{

		scanf("%d%d%d",&r,&c,&w);
		flag = c / w *r;
		flag =flag+ w - 1;
		if (c%w != 0)
			{flag++;}
		printf("Case #%d: %d\n",i,flag);
//Case #1: 3
	}
 
	return 0;
}
