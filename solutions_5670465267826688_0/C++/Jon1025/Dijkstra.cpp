/*
 * Dijkstra.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: jonathan
 *
 *      Solves the Dijkstra Problem.
 *
 */

#include <stdio.h>

typedef long long int ll;

int i_abs(int i)
{
	if (i>=0)
	{
		return i;
	}
	return -i;
}

int mtable[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

int mult(int i, int j)
{
	return (i/i_abs(i))*(j/i_abs(j))*mtable[i_abs(i)][i_abs(j)];
}

int main()
{
	FILE* file,*out;
	file = fopen("C-small-attempt0.in","r");
	out = fopen("outputCsmall.txt","w");
	ll num,i,j,k,ans,q,l,r,n;
	char temp;
	int* snums;
	fscanf(file,"%lld",&num);
	for (i=0;i<num;i++)
	{
		ans = 1;
		fscanf(file,"%lld",&j);
		fscanf(file,"%lld",&k);
		snums = new int[j];
		for (q=0;q<j;q++)
		{
			fscanf(file," %c",&temp);
			if (temp == 'i')
			{
				snums[q] = 2;
			}
			if (temp == 'j')
			{
				snums[q] = 3;
			}
			if (temp == 'k')
			{
				snums[q] = 4;
			}
		}
		for (q=1;q < j;q++)
		{
			snums[q] = mult(snums[q-1],snums[q]);
		}
		if (i_abs(snums[j-1]) > 1)
		{
			if (k%4 != 2)
			{
				ans = 0;
			}
		}
		if (snums[j-1] == 1)
		{
			ans = 0;
		}
		if (snums[j-1] == -1)
		{
			if (k%2 != 1)
			{
				ans = 0;
			}
		}
		if (ans != 0)
		{
			q = 0;
			r = 1;
			for (l=0;l<10 && l < k;l++)
			{
				for(n=0;n<j;n++)
				{
					if (q == 0 && mult(r,snums[n]) == 2)
					{
						q++;
					}
					if (q == 1 && mult(r,snums[n]) == 4)
					{
						q++;
					}
				}
				r = mult(r,snums[j-1]);
			}
			if (q != 2)
			{
				ans = 0;
			}
		}
		if (ans == 0)
		{
			fprintf(out,"Case #%lld: NO\n",i+1);
		}
		if (ans == 1)
		{
			fprintf(out,"Case #%lld: YES\n",i+1);
		}
		delete [] snums;
	}
}


