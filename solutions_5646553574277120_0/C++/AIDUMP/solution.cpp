// C_Less Money_More Problems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *IN,*OUT;
	
	IN = fopen ("C-small-attempt2.in" , "r");
	OUT = fopen ("C-small-attempt2.out" , "w");
	int i,j,k;
	int c,d,v;
	int coin[10];
	int count,max;
	int t;
	
	fscanf(IN,"%d",&t);
	for(i=0;i<t;i++)
	{
		fscanf(IN,"%d %d %d",&c, &d, &v);
		printf("Case:%d %d %d %d \n",i+1,c,d,v);
		for(j=0; j<d; j++)
		{
			fscanf(IN,"%d",&coin[j]);
			printf("%d ",coin[j]);
		}
		coin[j] = v+1;
		if(coin[0] == 1)
		{	
			j = 1;
			max = 1;
			count = 0;

		}
		else
		{
			j = 0;
			max = 1;
			count = 1;
		}

		while(1)
		{
			if(coin[j] == max+1)
			{
				max = max + coin[j];
				j++;
			}
			else if(coin[j] > max+1)
			{
				max = (max+1) * 2 - 1;
				count++;
			}
			else
			{
				max = max + coin[j];
				j++;
			}
			if(max >= v)
				break;
		}
		fprintf(OUT,"Case #%d: %d\n",i+1,count);
		printf("Case #%d: %d",i+1,count);
		//system("pause");
	}
	return 0;
}

