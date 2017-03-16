/*
 * main.cpp
 *
 *  Created on: 10 ???, 2015 ?.
 *      Author: Tigran
 */



#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

using namespace std;

int count_of_string_in_string( const std::string& inner, const std::string& outer )
{
	int r = 0;
	for ( int offset = 0; offset <= (int)outer.length() - (int)inner.length(); ++offset ) {
		if ( std::equal( inner.begin(), inner.end(), outer.begin() + offset ) )
			++r;
	}
	return r;
}

void solve_easy_visitor( int K, int L, int S, const std::string& Ks, const std::string& Ls,
		std::string& R, int& maxRepetitions, int& typedCount, int& casesCount )
{
	if ( (int)R.length() == S ) {
		int r = count_of_string_in_string( Ls, R );
		maxRepetitions = std::max( maxRepetitions, r );
		typedCount += r;
		casesCount++;
	}
	else {
		for ( int i = 0; i < K; ++i ) {
			R.push_back( Ks[ i ] );
			solve_easy_visitor( K, L, S, Ks, Ls, R, maxRepetitions, typedCount, casesCount );
			R.erase( R.length() - 1, 1 );
		}
	}
}

double solve_easy( int K, int L, int S, std::string Ks, std::string Ls )
{
	std::string R;
	int maxRepetitions = 0, typedCount = 0, casesCount = 0;
	solve_easy_visitor( K, L, S, Ks, Ls, R, maxRepetitions, typedCount, casesCount );
	double expBananas = (double)typedCount / (double)casesCount;
	return (double)maxRepetitions - expBananas;
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		int K, L, S;
		cin >> K >> L >> S;
		std::string Ks, Ls;
		cin >> Ks >> Ls;
		assert( (int)Ks.length() == K );
		assert( (int)Ls.length() == L );
		cout << "Case #" << tc << ": " <<
				setiosflags( ios::fixed | ios::showpoint ) <<
				setprecision( 8 ) <<
				solve_easy( K, L, S, Ks, Ls ) << endl;
	}
	return 0;
}
