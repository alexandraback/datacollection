#include <iostream>
#include <cstdio>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

long gcd( long a, long b )
{
  if ( a % b == 0 )
  {
	return b;
  } else {
	return gcd( b, a % b );
  }
}

bool isPow2( long b )
{
  while ( b % 2 == 0 )
  {
	b /= 2L;
  }
  return b == 1L;
}

int solve( long a, long b )
{
  int count = 0;
  while( b % 2 == 0 and a < b )
  {
	b /= 2L;
	count++;
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  for ( int t = 1; t <= T; t++ )
  {
	long a, b;
	char c;
	cin >> a >> c >> b;
	const long g = gcd( b, a );
	a /= g;
	b /= g;
	if ( not isPow2( b ) )
	{
	  printf( "Case #%d: impossible\n", t );
	} else {
	  const int ans = solve( a, b );
	  printf( "Case #%d: %d\n", t, ans );
	}
  }
}
