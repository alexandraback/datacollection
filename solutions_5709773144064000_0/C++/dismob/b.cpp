
#include <stdio.h>
#include <iostream>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

template< typename T >
std::string ToString( const T& v )
{
  std::ostringstream oss;
  oss << v;
  return oss.str();
}


int tests;

int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{
		double C, F, X;
		cin >> C >> F >> X;

		double res =0;
		double l =0, r =X;
		for( int loop=0; loop<100; ++loop )
		{
			const double m = (l+r)/2.0;
			double fa =2.0;
			double left =X;
			double elapsed =0;
			for( ; ; )
			{
				if ( left < C )
				{
					elapsed += left/fa;
					break;
				}

				const double ctime =left/fa;
				const double fatime =C/fa +left/(F+fa);
				//cout << "ROUND:ctime=" << ctime << " :: fatime=" << fatime<<endl;
				if ( ctime < fatime )
				{
					elapsed += ctime;
					break;
				}
				elapsed += C/fa;
				fa += F;
			}
			if ( elapsed < m )
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		res = l;


		cout << "Case #" << (curTest+1) << ": ";
		printf( "%.8lf", res );
		cout << endl;
	}

	return 0;
}

