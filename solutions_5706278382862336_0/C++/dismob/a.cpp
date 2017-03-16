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

template< typename T >
T ToType( const string& s )
{
	std::istringstream iss( s );
	T v;
	iss >> v;
  return v;
}

long long gcd( long long l, long long r )
{
	if ( r == 0 )
		return l;
	return gcd( r, l%r );
}


int tests;

int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{

		string s;
		cin >> s;
		const auto kPLen =s.find( "/" );

		long long p, q;
		p = ToType<long long>( s.substr( 0, kPLen ) );
		q = ToType<long long>( s.substr( kPLen+1 ) );
		//cout << p << ":" << q <<endl;

		const auto kGCD =gcd( p, q );
		p /= kGCD;
		q /= kGCD;

		int qpow =0;
		long long qq =q;

		bool ok =true;
		int res =0;
		while( qq > 0 )
		{
			if ( (qq%2) && (qq>1) )
			{
				ok =false;
				break;
			}
			++qpow;
			qq /= 2LL;
		}
		if ( ok )
		{
			const double kTerm =(double)(p)/(double)(q);
			double term =1;
			while( term > kTerm )
			{
				term *= 0.5;
				++res;
			}
		}

		cout << "Case #" << (curTest+1) << ": ";
		if ( ok )
		{
			cout << res;
		}
		else
		{
			cout << "impossible";
		}
		cout << endl;
	}

	return 0;
}

