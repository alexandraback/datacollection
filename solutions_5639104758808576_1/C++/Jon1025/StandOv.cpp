/*
 * StandOv.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: jonathan
 *
 *      Solves the standing ovation problem.
 *
 */

#include <stdio.h>

int main()
{
	FILE* file,*out;
	file = fopen("A-large.in","r");
	out = fopen("outputLarge.txt","w");
	long num,i,j,k,ans,q;
	char temp;
	int* snums;
	fscanf(file,"%ld",&num);
	for (i=0;i<num;i++)
	{
		ans = 0;
		fscanf(file,"%ld",&j);
		snums = new int[j+1];
		for (k=0;k<=j;k++)
		{
			fscanf(file," %c",&temp);
			snums[k] = temp - '0';
		}
		q = 0;
		for (k=0;k<=j;k++)
		{
			if (snums[k] > 0)
			{
				if (k > q)
				{
					ans += (k-q);
					q += (k-q);
				}
				q += snums[k];
			}
		}
		fprintf(out,"Case #%ld: %ld\n",i+1,ans);
		delete [] snums;
	}
	fclose(file);
	fclose(out);
}


