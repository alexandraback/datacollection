#include <iostream>

#include <vector>
#include <string>
#include <sstream>

#include <set>
#include <map>

#include <algorithm>

using namespace std;

template< typename T >
std::string ToString( const T& v )
{
  std::ostringstream oss;
  oss << v;
  return oss.str();
}


int tests;
vector<double> B[2];

int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{
		int N;
		cin >> N;
		B[0].resize( N ); B[1].resize( N );
		for( int i=0; i<2; ++i ) for( int x=0; x<N; ++x ) cin >> B[i][x];
		sort( B[0].begin(), B[0].end() );
		sort( B[1].begin(), B[1].end() );

		int y =0;
		{
			auto n =B[0];
			auto k =B[1];
			for( auto it : k )
			{
				auto low =lower_bound( n.begin(), n.end(), it );
				if ( low == n.end() )
				{
					n.erase( n.begin() );
				}
				else
				{
					n.erase( low );
					++y;
				}
			}
		}

		int z =0;
		{
			auto n =B[0];
			auto k =B[1];
			for( auto it : n )
			{
				auto low =lower_bound( k.begin(), k.end(), it );
				if ( low == k.end() )
				{
					k.erase( k.begin() );
					++z;
				}
				else
				{
					k.erase( low );
				}
			}
		}

		cout << "Case #" << (curTest+1) << ": ";
		cout << y;
		cout << " ";
		cout << z;
		cout << endl;
	}

	return 0;
}

