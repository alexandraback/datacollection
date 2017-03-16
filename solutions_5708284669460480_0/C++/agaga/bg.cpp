#include<cstdio>
using namespace std;
char x[10], y[10];
int a[10], b[10], c[10], maxi = 0, opcje = 0, suma = 0;
int k, l, s;
int f ( int ind )
{
  if ( ind == -1 ) 
  {
	int ile = 0;
	for ( int i = 0; i <= s - l; i ++ )
	{
	  bool ok = 1;
	  for ( int j = i; j <= i + l - 1 and ok; j ++ )
		if ( c[j] != b[j - i] ) ok = 0;
	  ile += ok;
	}
	if ( ile > maxi ) maxi = ile;
	opcje ++;
	suma += ile;
	return 0;
  }
  for ( int i = 0; i < k; i ++ )
  {
	c[ind] = a[i];
	f ( ind - 1 );
  }
  return 0;
}
int main ()
{
  int t;
  scanf ( "%d", &t );
  for ( int tt = 1; tt <= t; tt ++ )
  {
	scanf ( "%d %d %d", &k, &l, &s );
	scanf ( " %s %s", x, y );
	for( int j = 0; y[j]; j ++ ) b[j] = y[j] - 'a';
	for( int j = 0; x[j]; j ++ ) a[j] = x[j] - 'a';
	f ( s - 1 );
	double ret = maxi;
	double je = suma; je /= opcje;
	ret -= je;
	printf ( "Case #%d: %.7lf\n", tt, ret );
	maxi = 0;
	suma = 0;
	opcje = 0;
  }
}