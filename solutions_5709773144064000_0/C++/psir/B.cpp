#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define VI vector<int>

int main()
	{
	int TC;
	cin >> TC;
	for( int tc = 1; tc < TC+1; ++tc )
		{
		double C,F,X;
		cin >> C >> F >> X;

		double result = X / 2;
		double tbasic = 0;
		double rate = 2;
		while(1)
			{
			tbasic += C/rate;
			rate += F;
			double t = tbasic + X / rate;
			if (t < result )
				result = t;
			else 
				break;
			}
		
		printf("Case #%d: %.8lf\n",tc,result);
		}	
	return 0;
	}
