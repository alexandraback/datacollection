/*
 * Coin_Jam.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: jonathan
 */

#include <stdio.h>

/*int main()
{
	FILE* output;
	output = fopen("output-C-small.txt","w");
	fprintf(output,"Case #1: \n");
	long num = 0;
	int* digits = new int[7];
	for (long i = 0;i < 128;i++)
	{
		long k = i;
		long j = 0;
		long q = 0;
		while (k > 0)
		{
			if (k%2 == 1)
			{
				digits[q] = 1;
				j++;
			} else digits[q] = 0;
			q++;
			k /= 2;
		}
		if (j % 3 == 2 && num < 50) {
			fprintf(output,"1");
			for (long q = 6;q >= 0;q--)
			{
				if (digits[q] == 1) {
					fprintf(output,"11");
				} else fprintf(output,"00");
			}
			fprintf(output,"1 3 2 3 2 7 2 3 2 3 \n");
			num++;
		}
	}
	delete[] digits;
	digits = new int[6];
	for (long i = 0;i < 64;i++)
	{
		long k = i;
		long j = 0;
		long q = 0;
		while (k > 0)
		{
			if (k%2 == 1)
			{
				digits[q] = 1;
				j++;
			} else digits[q] = 0;
			q++;
			k /= 2;
		}
		if (j % 3 == 1 && num < 50) {
			fprintf(output,"11");
			for (long q = 5;q >= 0;q--)
			{
				if (digits[q] == 1) {
					fprintf(output,"11");
				} else fprintf(output,"00");
			}
			fprintf(output,"11 3 2 3 2 7 2 3 2 3 \n");
			num++;
		}
	}
	delete[] digits;
}*/

int main()
{
	FILE* output;
	output = fopen("output-C-large.txt","w");
	fprintf(output,"Case #1: \n");
	long num = 0;
	int* digits = new int[14];
	for (long i = 0;i < 16384;i++)
	{
		long k = i;
		long j = 0;
		long q = 0;
		while (k > 0)
		{
			if (k%2 == 1)
			{
				digits[q] = 1;
				j++;
			} else digits[q] = 0;
			q++;
			k /= 2;
		}
		if (j % 3 == 1 && num < 500) {
			fprintf(output,"11");
			for (long q = 13;q >= 0;q--)
			{
				if (digits[q] == 1) {
					fprintf(output,"11");
				} else fprintf(output,"00");
			}
			fprintf(output,"11 3 2 3 2 7 2 3 2 3 \n");
			num++;
		}
	}
	delete[] digits;
}

