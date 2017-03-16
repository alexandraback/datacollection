#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
//	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <string>
#include <limits.h>
#include <iterator>

#include <cctype>
#include <utility>
#include <numeric>
#include <complex>
#include <cmath>
#include <time.h>

using namespace std;

#include "MSGTime.h"
#include "MSGTimeUtil.h"
/*
int main()
{
	int A = 90000;
	int B = 100000;
	printf("1\n");
	printf("%d %d\n", A, B);
	srand(time(NULL));
	for(int i=0; i<A; i++)
	{
		printf("%f ", (double)rand()/RAND_MAX);
	}
}
*/
int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);
	
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);
				
		int A, B;		//A already typed, B total in pw
		cin >> A >> B;

		double * P = new double[A];
		double * ProbRight = new double[A];

		cin >> P[0];
		ProbRight[0] = P[0];
		//read in board
		for(int i=1; i<A; i++)
		{
			cin >> P[i];
			ProbRight[i] = ProbRight[i-1]*P[i];
		}
		
		double minExpected;
		//3 strategies
		//1. give up
		minExpected = B + 2;

		//2. finish typing
		double cost = (B-A+1)*ProbRight[A-1] + (2*B-A+2)*(1-ProbRight[A-1]);
		minExpected = min(minExpected,cost);

		//3. backspace i times
		for(int i=1; i<A; i++)
		{
			cost = (2*i+B-A+1)*ProbRight[A-1-i] + (2*i+2*B-A+2)*(1-ProbRight[A-1-i]);
			if (cost < minExpected)
				minExpected = cost;
		}		
		//backspace all the times
		cost = (A+B+1);
		if (cost < minExpected)
			minExpected = cost;

		double output = minExpected;
		printf("Case #%d: %f\n",test,output);
	}
}
/*
*/