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

int zero[10] = 
{
	0,
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	1000000000
};

ll check( int left, int num, int right )
{
	int tmp = num;
	int x = 0;
	while( tmp )
	{
		tmp /= 10;
		x++;
	}
	tmp = num;
	ll ans = 0;
	map< int, int > sb;
	fr(i,0,x)
	{
		int ft = tmp %10;
		tmp /= 10;
		tmp += ft * zero[x];
		if( tmp > num && tmp >= left && tmp <= right )
		{
			if( sb.find( tmp ) == sb.end() )
			{
				sb[tmp]=1;
				++ans;
				//pf("num = %d tmp = %d\n",num,tmp );
			}
		}
	}
	return ans;
}

int main()
{
	int T;
	sf("%d",&T);
	fr(ca,0,T)
	{
		int a,b;
		sf("%d%d",&a,&b);
		ll num = 0;
		fr(i,a,b+1)
		{
			num += check( a, i, b ); 
		}
		pf("Case #%d: %lld\n",ca+1, num);
	}
}
