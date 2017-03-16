#include <stdio.h>
#include <assert.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <map>

using namespace std;

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define fr(x,a,b) for( int x = a; x < b; ++x )
#define clr(x) memset(x,0,sizeof(x));
#define _clr(x) memset(x,-1,sizeof(x));

#define ll long long

char x[5] = {'a','e','i','o','u'};

int v[1000010];


int check( char t )
{
	fr(i,0,5)
	{
		if( t == x[i] )
			return 0;
	}
	return 1;
}

int main()
{
	int T;
	sf("%d",&T);
	
	fr(ca,0,T)
	{

		int n;
		clr( v );
		string str;
		cin>>str;
		cin>>n;
		
		int pos  = 0;
		while( pos < str.size() )
		{
			if( check( str[pos] ) )
			{
				int tmp = pos;
				while(pos < str.size() && check(str[pos]))
				{
					++pos;
				}
		//		pf("tmp = %d pos = %d\n",tmp, pos);
				for( int i = tmp; i <= pos - n; ++i )
				{
					v[i] = 1;
				}
			}
			else
			{
				++pos;
			}
		}

		ll ans = 0;

		int ft = str.size();
		for( int i = str.size()- 1; i >=0; --i )
		{
			if( v[i] )
			{
				ft = i;
			}
			if( ft < str.size() )
				ans +=  (int)str.size()- ft - n + 1;
			//pf("i = %d ft = %d ans = %lld\n",i,ft, ans);
		}
		pf("Case #%d: %lld\n",ca+1, ans);
		//cout<<ans<<endl;
	}
}
