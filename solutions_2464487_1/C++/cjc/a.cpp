#include <stdio.h>
#include <sstream>
#include <iostream>
#include <math.h>
#include <string>
#include <map>

using namespace std;

#define sf scanf
#define pf printf
#define fr(x,a,b) for( int x = a; x < b; ++x )
#define clr(x) memset(x,0,sizeof(x));

#define ll long long

ll r,t;
bool check( ll x )
{
	return 2 * x  - 1 + 2 * r<=t/x;
}

int main()
{
	int T;
	sf("%d",&T);
	fr(ca,0,T)
	{
		cin>>r>>t;

/*
		double x = ( 2 * r - 1 )/2;
		double ans = sqrt(t + x*x);
		ans = ans - x;
		cout<<ans<<endl;
		continue;
		*/

		ll l = 1, r = 2000000000;
		while( l + 1 < r )
		{
			ll mid = ( l + r ) / 2;
			if( check( mid ) )
			{
				l = mid;
			}
			else
				 r = mid;
		}

		printf("Case #%d: ",ca+1); 

		cout<<l<<endl;
	}
}
 
