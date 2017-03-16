#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int cases , Case = 1;
////////////

#define eps 1e-8


int main()
{	
	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   
		double c,f,x;
		cin >> c >> f >> x;

		double rate = 2.0;
		double timeSpent = 0;
		while(1)
		{
			double curTime = x/rate + timeSpent;
			timeSpent += c/rate;
			double nextTime = timeSpent + x/(rate+f);
			if( (curTime - nextTime)< eps )
			{
				printf("%0.8lf\n" , curTime);
				break;
			}
			else
			{
				rate+=f;
			}
		}
		
	}

	

	return 0;
}

