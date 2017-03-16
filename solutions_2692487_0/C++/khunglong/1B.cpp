// 1B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#define file_in "A-small-attempt2.in"
#define file_out "A.out" 

int test;          /* # of test case */
FILE *fi;
FILE *fo;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, k, a, n, step, d;
	int s[101];

    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);
	cout<<test;

    for (i=1; i<=test; i++)
    {
		cout<<i<<"/"<<test<<"...\n";
		fscanf(fi, "%d %d", &a, &n);

		for (j=0; j<n; j++)
			fscanf(fi, "%d", &s[j]);
		qsort (s, n, sizeof(int), compare);

		if (a==1)
		{
			fprintf(fo, "Case #%d: %d\n", i, n);
			continue;
		}

		step = 0;
		for (j=0; j<n; j++)
		{
			if (a>s[j]) 
				a += s[j];
			else
			{
				d = 0;
				k = j;
				while (k<n)
				{
					while (a<=s[k])
					{
						a += (a-1);
						d++;
					}
					a += s[k];
					k++;

					if (n-k+d < n-j) 
					{
						j=k;
						step += d;
						d = 0;
					}
				}

				if (d<n-j)	
				{
					step += d;
					break;
				}
				else	//delete all the rest
				{
					step += (n-j);
					break;
				}
			}
		}
		fprintf(fo, "Case #%d: %d\n", i, step);
	}

	fclose(fi);
    fclose(fo);
	return 0;
}

