/*
 * RankFile.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: jonathan
 */

#include <stdio.h>

int main()
{
	FILE* input;
	FILE* output;
	input = fopen("B-large.in","r");
	output = fopen("output-B-large.txt","w");
	long num_cases;
	long* heights = new long[2501];
	fscanf(input,"%ld",&num_cases);
	for (long i = 0;i < num_cases;i++)
	{
		long N;
		fscanf(input,"%ld",&N);
		printf("%ld %ld \n",i,N);
		for (long j = 0;j < 2501;j++)
		{
			heights[j] = 0;
		}
		for (long j = 0;j < (2*N-1)*N;j++)
		{
			long q;
			fscanf(input,"%ld",&q);
			++heights[q];
		}
		fprintf(output,"Case #%ld: ",i+1);
		for (long j = 0;j < 2501;j++)
		{
			if (heights[j] % 2 == 1)
			{
				fprintf(output,"%ld ",j);
			}
		}
		fprintf(output,"\n");
	}
	delete[] heights;
}
