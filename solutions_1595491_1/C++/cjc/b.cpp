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

int main()
{
	map<int, vector< pair<int,int> > > triplet;
	for( int i = 0; i < 11; ++i )
	{
		for( int j = 0; j <= i; ++j )
		{
			for( int k = 0; k <= j; ++k )
			{
				int a= i, b = j, c = k;
				if( a - c > 2 )continue;
				triplet[a+b+c].pb( mp(a,a-c >= 2) );
	//			pf("%d %d %d %d\n",a,b,c,a+b+c);
			}
		}
	}
	int T;
	sf("%d",&T);
	fr(i,0,T)
	{
		int n,s,p;
		sf("%d%d%d",&n,&s,&p);
		int num = 0;
		int totnum = 0;
		fr(k,0,n)
		{
			int sc = 0;
			sf("%d",&sc);

			vector< pair<int,int> > &ft = triplet[sc];
			int ok1 = 0, ok2 = 0;
			fr(j,0,ft.size())
			{
				if( ft[j].first >= p )
				{
					if( ft[j].second == 0 )
					{
						ok1 = 1;
					}
					else ++ok2;
				}
			}
			if( ok1 + ok2 )
			{
				if( !ok1 )
					++num;
				++totnum;
			}
		}
		pf("Case #%d: ",i+1);
		if( num > s )
		{
			pf("%d\n",totnum - num + s );
		}
		else
		{
			pf("%d\n",totnum);
		}
	}
}
