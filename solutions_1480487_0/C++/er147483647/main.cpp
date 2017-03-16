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

int T,t;
int N;
int J[300];
double S;
double res;

int main( )
{
	int i,j,k;
	double s;
	int n;

	freopen( "A-small-attempt5.in", "r", stdin );
	freopen( "A-small-attempt5.out", "w", stdout );

	scanf("%d",&T);

	for(t=1;t<=T;++t)
	{
		scanf("%d",&N);
		S = 0.0;
		for(i=0;i<N;++i)
		{
			scanf("%d",&J[i]);
			S += J[i];
		}
		printf("Case #%d: ",t);

		n = N;
		s = S;
		for(i=0;i<N;++i)
		{
			res = 100.0*(2.0*S - N*J[i])/(N*S);

			if(res <= 0)
			{
				s -= J[i];
				n -= 1;
			}
		}

		for(i=0;i<N-1;++i)
		{
			res = 100.0*(2.0*S - N*J[i])/(N*S);
			if(res <0)
				printf("%.7f ",0.0);
			else
				printf("%.7f ",100.0*(s + S - n*J[i])/(n*S));
		}

		res = 100.0*(2.0*S - N*J[i])/(N*S);
		if(res <0)
			printf("%.7f\n",0.0);
		else
			printf("%.7f\n",100.0*(s + S - n*J[i])/(n*S));
	}

	return 0;
}
