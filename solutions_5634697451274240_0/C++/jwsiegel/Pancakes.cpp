/*
 * Pancakes.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: jonathan
 */

#include <stdio.h>

int main()
{
	FILE* input;
	FILE* output;
	input = fopen("B-small-attempt0.in","r");
	output = fopen("output-B-small.txt","w");
	long num_cases;
	fscanf(input,"%ld",&num_cases);
	for (long i = 0;i < num_cases;i++)
	{
		char ch;
		int ans = 0;
		char top;
		bool start = true;
		ch = fgetc(input);
		while (ch != '+' && ch != '-') ch = fgetc(input);
		while (ch != '\n' && ch != EOF)
		{
			if (start == true) {
				top = ch;
				start = false;
			}
			if (top != ch) {
				ans++;
				top = ch;
			}
			ch = fgetc(input);
			while (ch != '+' && ch != '-' && ch != '\n' && ch != EOF) ch = fgetc(input);
		}
		if (top == '-') ans++;
		fprintf(output,"Case #%ld: %d \n",i+1,ans);
	}
}


