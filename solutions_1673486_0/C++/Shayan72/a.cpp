#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

int main(){	
	
	int T;
	cin >> T;
		
	for (int o = 1; o <= T; o++)
	{
		int typed,total;
		cin >> typed >> total;
		
		double prob[typed];
		
		for (int i = 0; i < typed; i++)
		{
			cin >> prob[i];
		}
		
		double expected[typed+2];
		
		int countBefore = 0;
		double lastProb = 0.0;
		int q;
		
		for ( q = 0; q <= typed ; q++)
		{
			int II = max( q-1 , 0 );
			
			int cc = pow( 2, II );
			cc += countBefore;
			
			double PR = 1.0;
			
			int j;
			for ( j = 0; j < typed-q; j++)
			{
				PR *= prob[j];
			}
			
			if( j < typed )
				PR *= 1.0 - prob[j];
			
			PR += lastProb;
			
			int moves = total - typed + 1 + ( 2*q );
			int moves2 = total - typed + 1 + ( 2*q ) + total + 1;
			expected[q] = (moves*PR) + ( moves2*(1.0-PR) );
			countBefore = cc;
			lastProb = PR;
		}
		
		expected[q] = total+2;
		printf( "Case #%d: %.8lf\n",o,*min_element(expected,expected+typed+2) );
	}
	
	return 0;
}

