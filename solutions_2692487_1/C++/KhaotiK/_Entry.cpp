#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <hash_set>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <memory>
#include <random>

using namespace std;

const char* inname = "Al.in";
const char* outname = "Al.out";

int main( int argc, char** argv )
{
	int T;
	freopen( inname, "r", stdin );
	freopen( outname, "w", stdout );

	int A, N;

	vector<int> motes;
	vector<int> cost(100, 0);
	motes.clear();

	scanf( "%d", &T );
	for( int iT=1; iT<=T; iT++ ) {
		cost.assign( cost.size(), 0 );
		motes.clear();
		printf( "Case #%d: ", iT );
		scanf( "%d %d", &A, &N );
		for( int i=0; i<N; i++ ) {
			int mo;
			scanf( "%d", &mo );
			motes.push_back( mo );
		}

		sort( motes.begin(), motes.end() );
		int sol = 0;
		int idx = 0;
		if( A<=1 ) {
			printf( "%d\n", N );
			continue;
		}
		while( 1 ) {
			if( motes.size() == 0 )
				break;
			if( motes[0] < A ) {
				A += motes[0];
				motes.erase( motes.begin() );
				idx++;
				continue;
			}
			A += A-1;
			cost[idx]++;
		}
		for( int i=1; i<N; i++ ) {
			cost[i] += cost[i-1];
		}
		int minop = N, op;
		for( int i=0; i<N; i++ ) {
			op = cost[i] + N-i-1;
			if( op < minop ) minop = op;
		}

		printf( "%d\n", minop );
	}
	//fclose( stdout );

	return 0;
}