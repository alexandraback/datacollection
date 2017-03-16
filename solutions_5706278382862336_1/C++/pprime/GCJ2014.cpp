//============================================================================
// Name        : GCJ2014.cpp
// Author      : Anmol Ahuja
//============================================================================

// #include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
using namespace std;

long long gcd ( long long a, long long b )
{
  long long c;
  while( a != 0 )
  {
     c = a;
     a = b%a;
     b = c;
  }
  return b;
}

int main()
{
	int t;
	scanf("%d",&t);
	for( int tcase=1; tcase<=t; ++tcase )
	{
		long long int p, q;
		scanf( "%lld/%lld", &p, &q );
		long long g = gcd( p,q );
		q /= g;
		p /= g;
		printf( "Case #%d: ", tcase );
		if( q && ((q & (q - 1)) == 0) )
		{
			double d = (double)q/p;
			int ans = 0;
			/*
			while( q )
			{
				q = q >> 1;
				ans +=1;
			}*/
			ans = ceil(log2(d));
			printf( "%d\n", ans );
		}
		else
			printf( "impossible\n" );
	}
	return 0;
}


/*int main()
{
	int t;
	scanf("%d",&t);
	for( int tcase=1; tcase<=t; ++tcase )
	{
		printf( "", tcase );
	}
	return 0;
}
*/
