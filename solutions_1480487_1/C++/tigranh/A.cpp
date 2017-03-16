
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct S
{
	int pos;
	int val;
};

bool operator<( const S& s1, const S& s2 )
{
	return s1.val < s2.val;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t )
	{
		int N;
		cin >> N;
		vector< S > s( N );
		for ( int i = 0; i < N; ++i ) {
			s[ i ].pos = i;
			cin >> s[ i ].val;
		}
		sort( s.begin(), s.end() );
		vector< int > PX( N );
		PX[ 0 ] = s[ 0 ].val;
		for ( int i = 1; i < N; ++i )
			PX[ i ] = PX[ i - 1 ] + s[ i ].val;
		int X = PX[ N - 1 ];
		int k;
		double H;
		for ( k = 0; k < N; ++k ) {
			H = (double)( X + PX[ k ] ) / (k + 1);
			if ( k == N - 1 || H < s[ k + 1 ].val )
				break;
		}
		vector< double > m( N );
		for ( int i = 0; i < N; ++i ) {
			if ( s[ i ].val >= H )
				m[ i ] = 0.0;
			else
				m[ i ] = 100.0 * ((H - s[ i ].val) / X);
		}
		vector< double > m2( N );
		for ( int i = 0; i < N; ++i )
			m2[ s[ i ].pos ] = m[ i ];
		cout << "Case #" << t << ":";
		for ( int i = 0; i < N; ++i ) {
			cout << " " << setiosflags( ios::fixed | ios::showpoint ) << setprecision( 7 ) << m2[ i ];
		}
		cout << endl;
	}
	return 0;
}
