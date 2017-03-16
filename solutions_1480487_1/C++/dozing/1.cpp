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

int main()
{
	int T,N;
	int i,j,n1;
	int temmax,maxv,sumc,sumv;
	int s[201],c[201];
	double pub,pri;
	freopen( "A-large.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	scanf( "%d\n", &T );
	for(i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);
		scanf( "%d", &N );
		maxv = sumv = sumc = 0;
		for (j = 0; j < N; ++j)
		{
			scanf( "%d", &s[j] );
			sumv += s[j];
			if (s[j] > maxv)
			{
				maxv = s[j];
			}
		}
		for (j = 0; j < N; ++j)
		{
			c[j] = maxv-s[j];
			sumc += c[j];
		}
		n1 = N;
		while (sumv < sumc)
		{
			temmax = sumc = n1 = 0;
			for (j = 0; j < N; ++j)
			{
				if (s[j] > temmax && s[j] < maxv)
				{
					temmax = s[j];
				}
			}
			maxv = temmax;
			for (j = 0; j < N; ++j)
			{
				if (s[j] > maxv)
				{
					c[j] = 0;
				}
				else
				{
					c[j] = maxv-s[j];
					++n1;
				}
				sumc += c[j];
			}
		}
		pub = 100*(double)(sumv-sumc)/(double)(sumv*n1);
		for (j = 0; j < N-1; ++j)
		{
			if (s[j] > maxv)
			{
				printf("%.6lf ",0);
			}
			else
			{
				pri = 100*(double)c[j]/(double)sumv;
				printf("%.6lf ",pri+pub);
			}
		}
		if (s[j] > maxv)
		{
			printf("%.6lf\n",0);
		}
		else
		{
			pri = 100*(double)c[j]/(double)sumv;
			printf("%.6lf\n",pri+pub);
		}
	}
	return 0;
}