#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<ll> perfects;

ll rev( ll x )
{
	ll r = 0;
	while( x > 0 )
	{
		r = r * 10 + x % 10;
		x /= 10;
	}
	return r;
}

bool palind( ll x )
{
	return x == rev( x );
}

int digits( ll x )
{
	int ret = 0;
	while( x > 0 )
	{
		x /= 10;
		++ret;
	}
	return ret;
}

ll pten( ll deg )
{
	ll ret = 1;
	while( deg-- )
		ret *= 10;
	return ret;
}

void precalc()
{
	perfects.push_back( 1 );
	perfects.push_back( 4 );
	perfects.push_back( 9 );
	for( ll x = 1; x <= 1000; ++x )
	{
		ll r = rev( x );
		ll pt = pten( digits( x ));
		ll t = x * pt + r;
		t *= t;
		if( palind( t ))
			perfects.push_back( t );
		for( ll i = 0; i < 10; ++i )
		{
			ll t = x * pt * 10 + i * pt + r;
			t *= t;
			if( palind( t ))
				perfects.push_back( t );
		}
	}
	sort( perfects.begin(), perfects.end());
}

int solve()
{
	ll a, b;
	cin >> a >> b;
	return upper_bound( perfects.begin(), perfects.end(), b ) - 
		lower_bound( perfects.begin(), perfects.end(), a );
}


int main()
{
	precalc();
	freopen( "C-large-1.in", "r", stdin );
	freopen( "C-large-1.out", "w", stdout );
	int t;
	cin >> t;
	for( int i = 1; i <= t; ++i )
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}