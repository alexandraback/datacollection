
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_consonant( char ch )
{
	switch( ch ) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return false;
		default:
			return true;
	}
}

long long solve( char* str, int n )
{
	int lens = strlen( str );
	typedef std::pair< int, int > range_type;
	typedef std::vector< range_type > ranges_type;
	ranges_type ranges;
	range_type temp_range( -1, -1 );
	for ( int i = 0; i <= lens; ++i ) {
		if ( i != lens && is_consonant( str[ i ] ) ) {
			if ( temp_range.first == -1 ) {
				temp_range.first = i;
			}
		}
		else {
			if ( temp_range.first != -1 ) {
				temp_range.second = i;
				if ( temp_range.second - temp_range.first >= n )
					ranges.push_back( temp_range );
				temp_range.first = temp_range.second = -1;
			}
		}
	}
	std::vector< int > rm;
	rm.push_back( 0 );
	for ( int i = 0; i < (int)ranges.size(); ++i ) {
		rm.push_back( ranges[ i ].first );
		rm.push_back( ranges[ i ].second );
	}
	rm.push_back( lens );
	long long r = 0;
	for ( int end_pos = n; end_pos <= lens; ++end_pos ) {
		int rightmost_begin_pos = -1;
		//
		std::vector< int >::iterator it = std::lower_bound( rm.begin(), rm.end(), end_pos );
		if ( (it - rm.begin()) % 2 == 0 ) {
			if ( (*(it-1)) <= end_pos - n )
				rightmost_begin_pos = end_pos - n;
			else {
				rightmost_begin_pos = (*(it - 2)) - n;
				if ( rightmost_begin_pos < 0 )
					rightmost_begin_pos = -1;
			}
		}
		else {
			rightmost_begin_pos = (*(it - 1)) - n;
			if ( rightmost_begin_pos < 0 )
				rightmost_begin_pos = -1;
		}
		//
		if ( rightmost_begin_pos != -1 )
			r += rightmost_begin_pos + 1;
	}
	return r;
}

int main()
{
	char str[ 1000000 + 50 ];
	int n;
	int T;
	cin >> T;
	for ( int tc = 1; tc <= T; ++tc ) {
		scanf( "%s", str );
		scanf( "%i", &n );
		cout << "Case #" << tc << ": " << solve( str, n ) << endl;
	}
}
