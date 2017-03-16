#include<cstdio>
#include<algorithm>
using namespace std;
long long f ( long long n )
{
  if ( n == 1 ) return 1;
  long long k = 10, p = 10;
  while ( k <= n )
  {
	if ( n >= k and n % p != 1 ) return f ( n - 1 ) + 1;
	k *= 100;
	p *= 10;
  }
  long long r = 0, c = n;
  while ( c )
  {
	r *= 10;
	r += c % 10;
	c /= 10;
  }
  if ( r < n ) return f ( r ) + 1;
  return f ( n - 1 ) + 1;
}
int main ()
{
  int t;
  scanf ( "%d", &t );
  for ( int tt = 1; tt <= t; tt ++ )
  {
	long long n;
	scanf ( "%lld", &n );
	printf ("Case #%d: %lld\n", tt, f(n) );
  }
}
