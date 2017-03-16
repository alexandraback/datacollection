#include <iostream>

#include <vector>
#include <string>
#include <sstream>

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

int n;
vector<string> cars;

vector<int> dp;

int main()
{
	cin >> tests;
	dp.resize( 100 );

	for( int curTest=0; curTest<tests; ++curTest )
	{

		cin >> n;
		cars.resize( n );
		for( int i=0; i<n; ++i ) cin >> cars[i];

		vector<int> p( n );
		for( int i=0; i<n; ++i ) p[i] = i;

		int res =0;
		do
		{
			bool ok =true;
			for( int i=0; i<30; ++i )
			{
				dp[i] =0;
			}
			int prev =-1;
			for( int i=0; (i<n)&&ok; ++i )
			{
				for( int j=0; (j<cars[p[i]].size())&&ok; ++j )
				{
					const auto c =cars[p[i]][j];
					if ( prev==-1 || prev!=c )
					{
						if ( dp[c-'a'] > 0 )
						{
							ok =false;
							break;
						}
						++dp[c-'a'];
					}
					prev =c;
				}
			}
			if ( ok ) ++res;
		}while( next_permutation( p.begin(), p.end() ) );

		cout << "Case #" << (curTest+1) << ": ";
		cout << res;
		cout << endl;
	}

	return 0;
}

