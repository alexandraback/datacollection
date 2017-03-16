#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <assert.h>
#include <stack>
#include <sstream>
#include <list>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))

#define fr(x,a,b) for( int x=a; x < b; ++x )
#define frr(x,a,b) for( int x=a;x>=b;--x)

#define pf printf
#define sf scanf

#define pb push_back
#define mp make_pair


double p[1000000];
int main()
{
	int t;
	sf("%d",&t);
	fr(ca,0,t)
	{
		clr( p );
		int n,m;
		sf("%d%d",&m,&n);
		p[0]=1;
		fr(i,1,m+1)
		{
			sf("%lf",&p[i]);
		}
		double t = 1;
		double ans = n + 2;

		for( int i = 0; i <= m; ++i )
		{
			t *= p[i];
			if( ans > ( t * ( n - i + 1 ) +  ( 1 - t ) * ( n - i + 1 + n + 1 ) + m-i ) )
			{
				ans = ( t * ( n-i+1) + ( 1 -t ) * ( n - i + 1 + n + 1 )  + m - i );
			}
		}
		pf("Case #%d: %lf\n",ca+1,ans);
	}
}
