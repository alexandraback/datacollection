#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>
using namespace std;

int T;
int A, B;
double p[200000];

double calc()
{
	double res, tmp;
	int Ta, Tn, Tr;
	double Pa;
	int i, j, k;

	Ta = B;
	Tn = A;
	Tr = Ta - Tn;

	//init for give up;
	res = Ta + 2;

	//calc back
	Pa = p[0];
	for(i = A-1; i >= 0; i--)
	{
		tmp = Pa * (2 * i + Tr + 1) + (1 - Pa) * (2 * i + Tr + 1 + Ta + 1);
		if(res > tmp)
			res = tmp;

		Pa = Pa * p[A-i];
	}

	return res;
}

int main( )
{
	int i,j,k;

	freopen( "A.in", "r", stdin );
	freopen( "A.out", "w", stdout );

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&A,&B);
		
		for(j=0;j<A;j++)
			scanf("%lf",&p[j]);



		printf("Case #%d: %.6f\n",i,calc());
		
	}

	return 0;
}
