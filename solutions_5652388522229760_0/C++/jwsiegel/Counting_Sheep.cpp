/*
 * Counting_Sheep.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: jonathan
 */


#include <stdio.h>

int main()
{
	FILE* input;
	FILE* output;
	input = fopen("A-small-attempt0.in","r");
	output = fopen("output-A-small.txt","w");
	long num_cases;
	fscanf(input,"%ld",&num_cases);
	for (long i = 0;i < num_cases;i++)
	{
		long n;
		fscanf(input,"%ld",&n);
		if (n == 0) {
			fprintf(output,"Case #%ld: INSOMNIA \n",i+1);
		} else {
		bool* digits = new bool[10];
		for (long j = 0;j < 10;j++)
		{
			digits[j] = false;
		}
		long q = 0;
		bool asleep = false;
		while (!asleep)
		{
			q += n;
			long temp = q;
			while (temp > 0)
			{
				digits[temp%10] = true;
				temp /= 10;
			}
			asleep = true;
			for (long j = 0;j < 10;j++)
			{
				if (!digits[j]) asleep = false;
			}
		}
		fprintf(output,"Case #%ld: %ld \n",i+1,q);
		}
	}
}

