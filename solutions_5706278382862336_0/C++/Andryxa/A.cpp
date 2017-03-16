
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull gcd( ull a, ull b )
{
	if( !b )
		return a;
	else
		return gcd( b, a % b );
}

bool pow2( ull a )
{
	ull t = 1;
	for( int i = 0; i <= 40; ++i, t *= 2 )
	{
		if( t == a )
			return 1;
		if( t > a )
			return 0;
	}
	return 0;
}

void main()
{
	int t;
	ifstream in;
	in.open( "A-small-attempt1.in", ios_base::in );
	in>>t;
	for( int i = 0; i < t; ++i )
	{
		ull p, q;
		char c;
		in>>p>>c>>q;
		ofstream out;
		out.open( "A.txt", ios_base::app );
		out<<"Case #"<<i+1<<": ";
		ull ggcd = 1;
		while( ( ggcd = gcd( p, q ) ) != 1 )
		{
			p /= ggcd;
			q /= ggcd;
		}
		if( pow2( q ) )
		{
			int ans = 0;
			for( ; p < q; ++ans )
				p *= 2;
			out<<ans<<endl;
		}
		else
			out<<"impossible\n";
	}
	in.close();
	//system( "pause" );
}
