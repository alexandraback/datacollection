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
using namespace std;

int cases , Case = 1;
////////////

char vv[128];

const int SIZE = 1000000+10;
char input[SIZE];

int main()
{	
	vv['a'] = 1;vv['e'] = 1;vv['i'] = 1;vv['o'] = 1;vv['u'] = 1;

	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		int n;
		cin >> input >> n;

		long long ans = 0;
		long long cur = 0;
		long long len = strlen(input);

		long long maax = 0;
		long long ok = 0;
		for(long long i = len; i--; )
		{
			if( vv[ input[i] ] )			
				cur = 0;			
			else
				++cur;
			maax = max(maax,cur);
			if( maax >= n )
			{
				if( cur >= n)
				{
					ans += len - i -n+1LL;
					ok = i;
				}
				else
				{
					ans += len - ok -n+1LL;
				}
			}
		}

		
		
		cout << ans << endl;
	}


	return 0;
}
