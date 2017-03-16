#include <stdio.h>
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		printf("Case #%d: ",kase);
		while (y!=0)
		{
			if (y>0) { printf("SN"); y--; }
			else     { printf("NS"); y++; }
		}
		while (x!=0)
		{
			if (x>0) 
			{ 
				printf("WE"); 
				x--; 
			}
			else     
			{
				printf("EW");
				x++; 
			}
		}
		printf("\n");
	}
	return 0;

}
