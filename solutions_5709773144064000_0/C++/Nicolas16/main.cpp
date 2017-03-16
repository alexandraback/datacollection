#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	double C, F, X;
	double start, best;
	double possible;
	int h;
	
	scanf("%d\n", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		scanf("%lf %lf %lf", &C, &F, &X);
		
		start = 0;
		best = (double)X/2.0;
		h = 0;
		while(start <= best)
		{
			start += (double)C/(double)(2+h*F);
			possible = start + (double)X/(double)(2+(h+1)*F);
			best = min(best, possible);
			//printf("Start %lf - Best %lf\n", start, best);
			h++;
		}
		
		printf("%.7lf\n", best);
	}

	return 0;
}
