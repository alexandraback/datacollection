/*
 * main.cpp
 *
 *  Created on: 10 ???, 2015 ?.
 *      Author: Tigran
 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int solve( int C, int D, ll V, std::vector< ll > Ds )
{
	std::sort( Ds.begin(), Ds.end() );
	ll maxSumTillNow = 0;
	int result = 0;
	for ( int Di = 0; Di < D; ++Di ) {
		ll d = Ds[ Di ];
		if ( d > maxSumTillNow + 1 ) {
			++result;
			ll newCoin = maxSumTillNow + 1;
			maxSumTillNow = newCoin * C + maxSumTillNow;
			--Di;
		}
		else {
			maxSumTillNow = d * C + maxSumTillNow;
		}
	}
	while ( maxSumTillNow < V ) {
		++result;
		ll newCoin = maxSumTillNow + 1;
		maxSumTillNow = newCoin * C + maxSumTillNow;
	}
	return result;
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		int C, D;
		ll V;
		cin >> C >> D >> V;
		std::vector< ll > Ds( D );
		for ( int i = 0; i < D; ++i )
			cin >> Ds[ i ];
		cout << "Case #" << tc << ": " << solve( C, D, V, Ds ) << endl;
	}
	return 0;
}
