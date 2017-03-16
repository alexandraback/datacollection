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

typedef std::pair<int, double> p;

int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);
	
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);
				
		int N;
		cin >> N;
		
		int * S = new int[N];
		int X=0;
		
		std::vector<p> scores;
		double * output = new double[N];

		for(int i=0; i<N; i++)
		{
			cin >> S[i];
			X += S[i];
			scores.push_back(p(S[i],i));
			output[i] = -1;
		}
		
		bool reset = true;
		int numScores = N;
		int XA = X;
		double average2;
		while (reset)
		{
			reset = false;
			double averageJ = XA / (double)numScores;
			double averageA = X / (double)numScores;
			average2 = averageJ+averageA;

			//if (X > 0)
			{
				for (int i=N-1; i>=0; i--)
				{
					if (S[i] > average2 && output[i] < 0)
					{
						output[i] = 0;
						XA-=S[i];
						numScores--;
						scores.erase(scores.begin()+i);
						reset = true;
					}
				}
			}
		}
		if (X == 0)
		{
			for(int i=0; i<N; i++)
			{
				if (output[i] < 0)
				{
					output[i] = 100/(double)numScores;
				}
			}
		}
		else
		{
			for (int i=0; i<N; i++)
			{
				double min;
				if (output[i] < 0)
				{
					min = 100*(average2 - S[i]) / X;
					output[i] = min;
				}
			}
		}
	
		printf("Case #%d:", test);
		for (int i=0; i<N; i++)
			printf(" %f",output[i]);
		printf("\n");
	}
}