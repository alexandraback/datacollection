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

long long gcd(long long a, long long b){ long long t; while ( b > 0 ) { a %= b; t = a; a = b; b =t; } return a; }


char buf[1024];
int main()
{	

	scanf("%d" , &cases);	
	while( cases-- )
	{			
		printf("Case #%d: " , Case++ );
		long long a,b;
		char aaa;
		cin >> a >> aaa >> b;


		long long g = gcd(a,b);
		a/=g;
		b/=g;

		int ans = 0;
		int one = -1;
		while( !( 
			(a == 1 && b == 1) /*||
			   (a == 0 ) */
			 
			   
			   )
			   )
		{
			a*=2;
			if( a > b  )
			{
				if( one == -1 )
					one = ans+1;
				a-=b;
				
			}

			g = gcd(a,b);
			a/=g;
			b/=g;

			++ans;
			if( ans > 40 )
				break;
		}
		if( ans == 0 )
			ans = 1;

		if( ans > 40 )
			puts("impossible");
		else 
		{
			if(one==-1)
				cout << ans << endl;
			else
				cout << one << endl;
		}


	}

	

	return 0;
}

