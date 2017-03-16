#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>
// gcc -std=gnu99 xxx.c -o xxx.exe [-lgmp]

int Imax(int,int);
double Dmax(double,double);
/*------------------------------------------------------------------------------------------*/

void main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attemptout.txt", "w", stdout);
	
	int T;
	//read number of test cases
	scanf("%d", &T);
	for (int ith=1; ith<=T; ith++)
	{
		// variables
		long A, B, K;
		long i, j, k;
		long long combs;
		scanf("%ld%ld%ld", &A, &B, &K);
		combs = 0;
		
		for (i=0;i<A;i++)
		{
			for(j=0;j<B;j++)
			{
				for (k=0;k<K;k++)
				{
					if ((i&j)==k) combs++;
				}
			}
		}
		
		printf("Case #%ld: %I64d\n", ith, combs);
	}
	
	fclose(stdin);
	fclose(stdout);
	
}


/*-------------------------------------------------------------------------------------------------------*/
/*
	write helper functions here
*/
int Imax(int a, int b)
{
	if (a>b)  return a;
	return b;
}

double Dmax(double a, double b)
{
	if (a>b) return a;
	return b;
}


