#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

ll rever ( ll n ) {
	ll x = 0;
	while ( n ) {
		x *= 10;
		x += n % 10;
		n /= 10;
	}
	return x;
}

ll pot ( ll x, int base ) {
	ll p = 1;
	for ( int i = 0; i < base; i ++ )
		p *= x;
	return p;
}

ll solve ( ll n ) {

	if ( n == 0 ) return 0;
	if ( n < 10 ) return n;
	if ( n % 10 == 0 ) return solve (n - 1) + 1;

	ll x = n, sz = 1;
	while ( x > 9 ) {
		x /= 10;
		sz ++;
	}
	ll mult = pot ( 10, sz-1 ), mult2;
	ll op1 = n;

	if ( x == 1 ) op1 =  n % mult;

	mult2 = pot ( 10, (sz+1)/2 );
	op1 = min ( op1, n%(mult2) + rever(n/(mult2)) );
	mult2 /= 10;
	if ( sz % 2 )
		op1 = min( op1, n%(mult2) + rever(n/mult2));
	return op1 + solve ( mult - 1 ) + 1;
}

int main() {

	freopen ( "A1.in", "r", stdin );
	freopen ( "SalidaA.out", "w", stdout );

	int ntc;
	ll n;

	cin >> ntc;
	
	for ( int tc = 1; tc <= ntc; tc ++ ) {

		cin >> n;
		cout << "Case #" << tc << ": " << solve ( n ) << '\n';
	}


	return 0;
}
