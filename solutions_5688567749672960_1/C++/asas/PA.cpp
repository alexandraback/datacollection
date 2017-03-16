#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <sstream>
#include <map>
#include <vector>
#define phb push_back
#define ppb pop_back
using namespace std ;
inline long long in(long long d=0,char q=0,long long c=1){while(q!='-'&&q!=EOF&&(q<48||q>57))q=getchar();if(q==EOF)return EOF;if(q=='-')c=-1,q=getchar();do d=d*10+(q^48),q=getchar();while(q<58&&q>47);return c*d;}
//long long dp[ 1000001 ] = {} ;
//long long dp2[ 1000001 ] = {} ;
//long long dp3[ 1000001 ] = {} ;
int main()
{
//	dp[ 1 ] = 1 ;
//	for ( long long i = 1 , j , k ; i < 1000001 ; i ++ )
//	{
//		if ( dp[ i + 1 ] == 0 )
//		{
//			dp[ i + 1 ] = dp[ i ] + 1 ;
//			dp2[ i + 1 ] = i ;
//			dp3[ i + 1 ] = 0 ;
//		}
//		else
//		{
//			if ( dp[ i ] + 1 < dp[ i + 1 ] ) dp2[ i + 1 ] = i , dp3[ i + 1 ] = 0 ;
//			dp[ i + 1 ] = min( dp[ i + 1 ] , dp[ i ] + 1 ) ;
//		}
//		j = i , k = 0 ;
//		while ( j != 0 )
//		{
//			k = k * 10 + j % 10 ;
//			j /= 10 ;
//		}
//		if ( dp[ k ] == 0 )
//		{
//			dp2[ k ] = i ;
//			dp[ k ] = dp[ i ] + 1 ;
//			dp3[ k ] = 1 ;
//		}
//		else
//		{
//			if ( dp[ i ] + 1 < dp[ k ] ) dp2[ k ] = i , dp3[ k ] = 1 ;
//			dp[ k ] = min( dp[ k ] , dp[ i ] + 1 ) ;
//		}
//	}
//	for ( long long i = 1 ; i < 1000001 ; i ++ )
//	{
//		long long n = i , res = 0 ;
//		long long len = 0 ;
//		long long temp = n ;
//		while ( n != 0 )
//		{
//			len = 0 , temp = n ;
//			while ( temp != 0 )
//			{
//				temp /= 10 , len ++ ;
//			}
//			len = len - len / 2 ;
//			temp = n % ( long long )pow( 10.0 , (double)(len) ) ;
//			if ( temp > 1 )
//			{
//				res += temp - 1 ;
//				n -= temp - 1 ;
//			}
//			else if ( temp == 1 )
//			{
//				long long j = n , k = 0 ;
//				while ( j != 0 )
//				{
//					k = k * 10 + j % 10 ;
//					j /= 10 ;
//				}
//				if ( k < n )
//				{
//					res ++ ;
//					n = k ;
//				}
//				else
//				{
//					res ++ ;
//					n -- ;
//				}
//			}
//			else
//			{
//				res ++ ;
//				n -- ;
//			}
//		}
//		if ( res != dp[ i ] )
//		{
//			cout << i << ' ' << dp[ i ] << ' ' << res << endl ;
//		}
//	}
	long long t = in() , Case = 1 ;
	while ( t -- )
	{
		long long n = in() , res = 0 ;
		long long len = 0 ;
		long long temp = n ;
		while ( n != 0 )
		{
			len = 0 , temp = n ;
			while ( temp != 0 )
			{
				temp /= 10 , len ++ ;
			}
			len = len - len / 2 ;
			temp = n % ( long long )pow( 10.0 , (double)(len) ) ;
			if ( temp > 1 )
			{
				res += temp - 1 ;
				n -= temp - 1 ;
			}
			else if ( temp == 1 )
			{
				long long j = n , k = 0 ;
				while ( j != 0 )
				{
					k = k * 10 + j % 10 ;
					j /= 10 ;
				}
				if ( k < n )
				{
					res ++ ;
					n = k ;
				}
				else
				{
					res ++ ;
					n -- ;
				}
			}
			else
			{
				res ++ ;
				n -- ;
			}
		}
		cout << "Case #" << Case ++ << ": " << res << endl ;
	}
}


