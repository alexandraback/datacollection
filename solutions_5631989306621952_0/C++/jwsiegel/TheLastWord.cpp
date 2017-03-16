/*
 * TheLastWord.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: jonathan
 */


#include <stdio.h>
#include <string>

using namespace std;

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
		string s = "";
		char ch;
		ch = fgetc(input);
		while (ch < 65 || ch > 90) {ch = fgetc(input);}
		while (ch >= 65 && ch <= 90)
		{
			if (ch >= s[0]) {
				s.insert (0, 1, ch);
			} else
			{
				s += ch;
			}
			ch = fgetc(input);
		}
		fprintf(output,"Case #%ld: %s \n",i+1,s.c_str());
	}
}

