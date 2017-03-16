#include <stdafx.h>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>

using namespace std;

const long maxn=205;
const double eps=1.0e-6;
const double eps2=1.0e-9;

long a[maxn];
long n;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long tests;
	scanf("%ld",&tests);
	for (long test=1;test<=tests;test++)
	{
		scanf("%ld",&n);
		long sum=0;
		for (long q=1;q<=n;q++)
		{
			scanf("%ld",&a[q]);
			sum+=a[q];
		}
		printf("Case #%ld: ",test);
		for (long it=1;it<=n;it++)
		{
			double start=0.0;
			double finish=100.0;
			while(finish-start>eps)
			{
				double middle=(start+finish)/2;
				double bound=middle*sum/100.0+a[it];
				double s=middle;
				for (long choice=1;choice<=n;choice++) if (choice!=it)
				{
					if (bound-a[choice]>eps2)
						s+=100.0*(bound-a[choice])/sum;
				}
				/*if (100.0-s>-eps2)
					finish=middle;
				else start=middle;*/
				if (100.0-s>-eps2)
					start=middle;
				else finish=middle;
			}
			printf("%0.6lf ",start);
		}
		printf("\n");
	}
}