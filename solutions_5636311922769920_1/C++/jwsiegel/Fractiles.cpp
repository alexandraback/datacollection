/*
 * Fractiles.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: jonathan
 */


#include <stdio.h>

typedef long long int ll;

int main()
{
	FILE* input;
	FILE* output;
	input = fopen("D-large.in","r");
	output = fopen("output-D-large.txt","w");
	long num_cases;
	fscanf(input,"%ld",&num_cases);
	for (long i = 0;i < num_cases;i++)
	{
		ll K;
		ll C;
		ll S;
		fscanf(input,"%lld",&K);
		fscanf(input,"%lld",&C);
		fscanf(input,"%lld",&S);
		if (S < K/C) {
			fprintf(output,"Case #%ld: IMPOSSIBLE \n",i+1);
		} else {
			fprintf(output,"Case #%ld: ",i+1);
			ll num = 0;
			ll p = 1;
			ll t = 0;
			for (ll j = 0;j < K;j++)
			{
				num += j*p;
				p *= K;
				t++;
				if (t == C) {
					fprintf(output,"%lld ",num+1);
					t = 0;
					num = 0;
					p = 1;
				}
			}
			if (t > 0) fprintf(output,"%lld \n",num+1);
			else fprintf(output,"\n");
		}
	}
}

