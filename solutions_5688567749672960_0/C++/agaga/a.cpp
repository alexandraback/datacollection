#include<cstdio>
#include<algorithm>
using namespace std;
int tab[1000005];
int f ( int n )
{
  if ( tab[n] ) return tab[n];
  if ( n == 1 ) return 1;
  if ( n % 10 == 0 ) 
  {
	tab[n] = f ( n - 1 ) + 1;
	return tab[n];
  }
  int r = 0, c = n;
  while ( c )
  {
	r *= 10;
	r += c % 10;
	c /= 10;
  }
  if ( r < n ) 
  {
	int ans = f ( r ) + 1;
	tab[n] = min ( ans, f(n - 1) + 1 );
	return tab[n];
  }
  tab[n] = f(n-1) + 1;
  return tab[n];
}
int main ()
{
  int t;
  scanf ( "%d", &t );
  for ( int tt = 1; tt <= t; tt ++ )
  {
	int n;
	scanf ( "%d", &n );
	printf ("Case #%d: %d\n", tt, f(n) );
  }
}
