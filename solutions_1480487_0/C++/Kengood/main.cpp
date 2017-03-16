//compiled in vc
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
// C++
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;

int cases , Case = 1;
////////////

int input[1024];

int main()
{	
	scanf("%d" , &cases);

	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   
		int n;
		cin >> n;
		double total = 0;
		int not0 = 0;
		for(int i = 0;i < n; ++i)
		{
			cin >> input[i];
			total += input[i];
			if( input[i] > 0.0 )
				++not0;
		}

		double mark = total/(double)n;
		double base = 100.0/(double)n;
		for(int i = 0;i < n; ++i)
		{
			//if( input[i] )
			{
				double left = mark - (double)input[i];
				double ans = base;
				if( total > 1e-5)
				{
					ans = base + left*(base/mark);
					if( ans < 1e-5)
						ans = 0;
				}
				
				printf("%.7lf " ,  ans);
			}
			//else
				//printf("%.7lf " , 0);
		}
		puts("");
		
	}


	return 0;
}
