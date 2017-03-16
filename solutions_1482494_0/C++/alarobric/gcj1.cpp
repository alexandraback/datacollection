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
#include <list>
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
struct level
{
	bool operator<(const level&rhs) const
	{
		return B > rhs.B;		//purposely wrong
	}
	int A;
	int B;
	bool Ac;
};

int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);
	
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);
				
		int N;
		cin >> N;

		std::list<level> levels;

		for(int i=0; i<N; i++)
		{
			level lev;
			cin >> lev.A;
			cin >> lev.B;
			lev.Ac = false;
			levels.push_back(lev);
		}

		levels.sort();

		bool possible = true;
		int stars = 0;
		int numTries = 0;
		while (levels.size() > 0)
		{
			bool did = false;
			for(auto it=levels.begin(); it!=levels.end(); it++)
			{
				if(it->B <= stars)		//can 2 star
				{
					if (it->Ac == false)	//and haven't 1 starred yet
					{
						stars += 2;
					}
					else
					{
						stars++;
					}
					numTries++;
					did = true;
					it = levels.erase(it);
					break;
				}
			}
			if(!did)
			{
				for(auto it=levels.begin(); it!=levels.end(); it++)
				{
					if(it->A <= stars && it->Ac == false)	//can 1 star
					{
						it->Ac = true;
						stars++;
						did = true;
						numTries++;
						break;
					}
				}
			}
			if (!did)
			{
				//couldn't do anything
				possible = false;
				break;
			}
		}
		
		
		if (possible)
		{
			int output = numTries;
			printf("Case #%d: %d\n",test,output);
		}
		else
			printf("Case #%d: Too Bad\n",test);
	}
}


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