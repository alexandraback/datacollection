#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

const double M_PI = 4.0*atan(1.0);

int main()
{
	
	assert(freopen("B-small-attempt2.in", "r", stdin));
	assert(freopen("output.out", "w", stdout));

	int nCase;
	int row,col;
	scanf("%d",&nCase);
	int E,R,N;
	int* values;
	int gain;
	int maxValue = 0,maxIndex = 0,nextMax;
	for(int i = 0 ; i < nCase ; i++)
	{
		

		scanf("%d",&E);
		scanf("%d",&R);
		scanf("%d",&N);
		int maxE = E;

		values = new int[N];

		maxValue = 0;
		maxIndex = 0;
		gain = 0;
		nextMax = 0;
		for(int j = 0 ; j < N ; j++)
		{
			scanf("%d",&values[j]);
			if(values[j] >  maxValue)
			{
				maxValue = values[j];
				maxIndex = j;
			}
		}

		if( R >= E)
		{
			for(int j = 0 ; j < N ; j++)
			{
				gain += values[j] * E;
			}
		}
		else
		{
			for(int j = 0 ; j < N ; j++)
			{
				for(int k= j ; k < N ; k++)
				{
					if(values[k]>values[j])
					{
						nextMax = k;
						break;
					}
				}
				if(nextMax == j)
				{
					gain += values[j] * E;
					E = R;
				}
				else
				{
					int diff = nextMax-j;
					if(diff < 0) 
					{
						gain += values[j] * E;
						E = R;
					}
					else if((diff ) * R  + E> maxE)
					{
						int temp;
						if(((diff ) * R  + E - maxE) > E)
						{
						gain +=values[j] * E;
						
						E = R;
						}
						else
						{
						gain += values[j] * ((diff ) * R  + E - maxE);
						E -= ((diff ) * R  + E - maxE);
						E += R;
						}
					}
					else
					{
						gain += 0 ;
						E += R;
						if(E > maxE) E = maxE;
					}
				}
				
			}
		}

	printf("Case #%d: %d\n",i+1,gain);

	delete values;

	}
	

	return 0;
}