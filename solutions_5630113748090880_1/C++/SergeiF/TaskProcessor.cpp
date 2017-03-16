#include "TaskProcessor.h"
#include <map>

void CTaskProcessor::findMissingLine( const vector< vector<int> >& lines, vector<int>& missingLine )
{
	assert( lines.size() > 0 );
	const int N = lines[0].size();
	assert( lines.size() == 2 * N - 1 );
	for( int i = 0; i < (int)lines.size(); i++ ) {
		assert( lines[i].size() == N );
	}
	
	std::map<int, int> counts;
	for( int i = 0; i < 2 * N - 1; i++ ) {
		for( int j = 0; j < N; j++ ) {
			const int val = lines[i][j];
			if( counts.find( val ) == counts.end() ) {
				counts.insert( pair<int, int>( val, 1 ) );
			} else {
				counts[val] += 1;
			}
		}
	}

	missingLine.clear();
	for( std::map<int,int>::iterator it = counts.begin(); it != counts.end(); it++ ) {
		if( it->second % 2 == 1 ) {
			missingLine.push_back( it->first );
		}
	}
	assert( missingLine.size() == N );
	std::sort( missingLine.begin(), missingLine.end() );
}
