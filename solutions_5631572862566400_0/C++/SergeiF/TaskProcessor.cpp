#include "TaskProcessor.h"
#include <map>

int CTaskProcessor::findMaxCircleLength( const vector<int>& bffs )
{
	const int n = bffs.size();
	assert( n > 0 );

	//	all pairs
	int numberOfPairs = 0;
	vector<int> pairs;
	pairs.assign( n, -1 );
	for( int i = 0; i < n; i++ ) {
		const int j = bffs[i];
		if( bffs[j] == i ) { 
			pairs[i] = j;
			if( i < j ) {
				numberOfPairs++;
			}
		}
	}

	//	max path for each x
	vector<int> lengths;
	vector<int> pathEnds;	//	-1 for circle, -2 for path with circle on end, or the index of the prev to last element for path with pair on end
	lengths.assign( n, 0 );
	pathEnds.assign( n, -1 );
	for( int i = 0; i < n; i++ ) {
		vector<bool> visited;
		visited.assign( n, false );
		visited[i] = true;
		int j = bffs[i];
		int prev = i;
		int prevPrev = -1;
		int length = 1;
		while( j != i && !visited[j] && j != prevPrev ) {
			length++;
			prevPrev = prev;
			prev = j;
			visited[j] = true;
			j = bffs[j];
		}
		if( j != i ) {
			if( j == prevPrev ) {
				pathEnds[i] = j;
				length -= 1;
			} else {
				pathEnds[i] = -2;
			}
		}
		assert( length >= 2 && length <= n );
		lengths[i] = length;
	}

	//	max circles
	int maxCircleLength = -1;
	for( int i = 0; i < n; i++ ) {
		if( pathEnds[i] == -1 ) {
			maxCircleLength = max( maxCircleLength, lengths[i] );
		}
	}

	//	max left/right tails for each pair
	vector<int> maxTails;
	maxTails.assign( n, 1 );
	for( int i = 0; i < n; i++ ) {
		if( pathEnds[i] >= 0 ) {
			const int j = pathEnds[i];
			maxTails[j] = max( maxTails[j], lengths[i] );
		}
	}

	//	max circle with pair inside
	int maxCircleWithPairLength = -1;
	for( int i = 0; i < n; i++ ) {
		if( pairs[i] != -1 ) {
			const int j = pairs[i];
			const int length = maxTails[i] + maxTails[j];
			maxCircleWithPairLength = max( maxCircleWithPairLength, length );
		}
	}

	const int maxResultWithPairInside = maxCircleWithPairLength > 0 
		? maxCircleWithPairLength + 2 * (numberOfPairs - 1) : 0;

	const int maxResultPairsOnly = 2 * numberOfPairs;

	const int result = max( maxCircleLength, max( maxResultPairsOnly, maxResultWithPairInside ) );
	return result;
}
