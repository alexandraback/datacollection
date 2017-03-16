/*
 * D.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: tigran
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

long long make_int( int K, int C, const vector< int >& takes )
{
	assert( (int)takes.size() == C );
	assert( all_of( takes.begin(), takes.end(), [K]( int val ){ return val <= K; } ) );
	long long result = 0;
	for ( int i = 0; i < (int)takes.size(); ++i ) {
		result *= K;
		result += (takes[ i ] - 1);
	}
	return result + 1;
}

vector< long long > solve( int K, int C )
{
	vector< int > takes;
	for ( int i = 1; i <= K; ++i )
		takes.push_back( i );
	for ( int i = 1; i <= K * C; ++i )
		takes.push_back( K );
	vector< vector< int > > rv;
	for ( int partition = 0; rv.empty() || rv.back().back() < K; ++partition ) {
		rv.push_back( vector< int >(
				takes.begin() + (partition * C),
				takes.begin() + ((partition + 1) * C) ) );
	}
	vector< long long > result;
	for ( int i = 0; i < (int)rv.size(); ++i )
		result.push_back( make_int( K, C, rv[ i ] ) );
	return result;
}

int main()
{
	int T, K, C, S;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		cin >> K >> C >> S;
		vector< long long > r = solve( K, C );
		cout << "Case #" << t << ":";
		if ( (int)r.size() > S )
			cout << " IMPOSSIBLE";
		else {
			for ( int i = 0; i < (int)r.size(); ++i )
				cout << " " << r[ i ];
		}
		cout << endl;
	}
	return 0;
}
