#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

inline void rev( string &s, int i, int j )
{
	int  l=i, m=j ;
	
	while( i < j )
	{
		swap( s[i], s[j] );		
		i++ ;  
		j-- ;
	}

	for( ; l<=m; l++ )
		if( s[l] == '-' )  s[l] = '+' ;
		else  s[l] = '-' ;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen( "in", "r", stdin );
	freopen( "out", "w", stdout );

	int tt;
	cin >> tt ;
	for( int t=1; t<=tt; t++ )
	{
		string s ;
		cin >> s ;

		int  ans = 0 ;
		for( int i=s.size()-1; i>=0 ; i-- )
		if( s[i] == '-' )
		{
			if( s[0] == '-' )   ans++ ;
			else  ans += 2 ;
			for( int j=0; j<s.size(); j++ )
				if( s[j] == '+' )  s[j] = '-' ;
				else break;
			rev(s,0,i);
		}

		cout << "Case #" << t << ": " << ans << endl ;
	}

	return 0 ;
}