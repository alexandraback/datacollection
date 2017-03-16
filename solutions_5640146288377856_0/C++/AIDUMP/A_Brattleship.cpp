// A_Brattleship.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{

	FILE *IN,*OUT;
	
	IN = fopen ("A-small-attempt2.in" , "r");
	OUT = fopen ("A-small-attempt2.out" , "w");
	int i,j,k;
	int r,c,w;
	int count;
	int t;

	fscanf(IN,"%d",&t);
	for(i=0;i<t;i++)
	{
		fscanf(IN,"%d %d %d",&r, &c, &w);
		printf("Case:%d %d %d %d ",i+1,r,c,w);
		if(w == 1)
		{
			fprintf(OUT,"Case #%d: %d\n",i+1, r*c);
			printf("   ans:%d",r*c);
		}
		else if(w == c)
		{
			fprintf(OUT,"Case #%d: %d\n",i+1, c);
			printf("   ans:%d",c);
		}
		else if(w*2 >= c)
		{
			fprintf(OUT,"Case #%d: %d\n",i+1, w+1);
			printf("   ans:%d",w+1);
		}
		else
		{
			if(c%w==0)
			{
				fprintf(OUT,"Case #%d: %d\n",i+1, c/w+w-1);
				printf("   ans:%d",c/w+w-1);
			}
			else
			{
				fprintf(OUT,"Case #%d: %d\n",i+1, c/w+w);
				printf("   ans:%d",c/w+w);
			}

		}
		//system("pause");
	}
	return 0;
}

