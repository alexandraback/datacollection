#include <iostream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

bool is_palindrome( long long int const n )
{
  auto const s = to_string( n );
  return equal( s.begin(), s.begin() + s.size() / 2, s.rbegin() );
}

int main()
{
  set<long long int> v;

  long long int N=100000000000000;
  for( long long int i=1; i<=sqrt(N); ++i ) {
    auto const pn = pow( i, 2 );
    if ( is_palindrome( i ) && is_palindrome( pn ) ) {
      v.insert( pn );
    }
  }

  size_t n;
  cin >> n;
  for( size_t iii=0; iii<n; ++iii ) {
    long long int a, b;
    cin >> a >> b;

    size_t result = 0;
    for( auto const& s : v ) {      
      if ( s < a )
	continue;
      if ( s > b )
	break;

      ++result;
    }

    cout << "Case #" << (iii+1) << ": " << result << endl;
  }
}
