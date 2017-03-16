#include<cstdio>
#include<algorithm>
using namespace std;
int tab[10], x[50];
int c, d, v;
int main()
{
  int t;
  scanf ( "%d", &t );
  x[0] = 1;
  for ( int tt = 1; tt <= t; tt ++ )
  {
	int nowi = 0;
	scanf ( "%d %d %d", &c, &d, &v );
	for ( int i = 1; i <= v; i ++ ) x[i] = 0;
	for ( int j = 1; j <= d; j ++ ) 
	{
	  scanf ( "%d", &tab[j] );
	  for ( int i = v - tab[j]; i >= 0; i -- )
		if ( x[i] ) x[i + tab[j]] = 1;
	}
	for ( int j = 1; j <= v; j ++ )
	{
	  if ( x[j] == 0 )
	  {
		nowi ++;
		for ( int i = v - j; i >= 0; i -- )
		  if ( x[i] ) x[i + j] = 1;
	  }
	}
	printf ( "Case #%d: %d\n", tt, nowi );
  }
}