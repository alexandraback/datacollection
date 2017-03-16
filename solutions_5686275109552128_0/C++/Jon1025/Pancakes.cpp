/*
 * Pancakes.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: jonathan
 *
 *      Solves the Pancakes problem.
 */

#include <stdio.h>

typedef long long int ll;

ll num_spec[1001][1001]; // the number of special rounds required to get rid of n pancakes given k regular rounds
						 // initialized dynamically at the beginning of the program.

int main()
{
	FILE* file,*out;
	file = fopen("B-small-attempt0.in","r");
	out = fopen("outputBsmall.txt","w");
	ll num,i,j,k,ans,q,l;
	char temp;
	ll* snums;
	for (i=0;i<1001;i++)
	{
		num_spec[i][0] = 0;
		num_spec[i][1] = i-1;
	}
	num_spec[0][1] = 0;
	for (j=2;j<1001;j++)
	{
		for (i=0;i<=j;i++)
		{
			num_spec[i][j] = 0;
		}
		for (i=j+1;i<1001;i++)
		{
			q = num_spec[i-1][j-1];
			for (k=1;k<=i/2;k++)
			{
			if (q > 1 + num_spec[k][j] + num_spec[i-k][j])
			{
				q = 1 + num_spec[k][j] + num_spec[i-k][j];
			}
			}
			num_spec[i][j] = q;
		}
	}
	fscanf(file,"%lld",&num);
	for (i=0;i<num;i++)
	{
		fscanf(file,"%lld",&j);
		snums = new ll[j];
		for (k=0;k<j;k++)
		{
			fscanf(file,"%lld",&snums[k]);
		}
		ans = 10000;
		for (k=1;k<=1000;k++)
		{
			q = k;
			for (l=0;l<j;l++)
			{
				q += num_spec[snums[l]][k];
			}
			if (q < ans)
			{
				ans = q;
			}
		}
		fprintf(out,"Case #%lld: %lld\n",i+1,ans);
		delete [] snums;
	}
}


