#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#define phb push_back
#define ppb pop_back
using namespace std ;
inline int in(int d=0,char q=0,int c=1){while(q!='-'&&q!=EOF&&(q<48||q>57))q=getchar();if(q==EOF)return EOF;if(q=='-')c=-1,q=getchar();do d=d*10+(q^48),q=getchar();while(q<58&&q>47);return c*d;}
int dp[ 1000001 ] = {} ;
int main()
{
	dp[ 1 ] = 1 ;
	for ( int i = 1 , j , k ; i < 1000001 ; i ++ )
	{
		if ( dp[ i + 1 ] == 0 )
		{
			dp[ i + 1 ] = dp[ i ] + 1 ;
		}
		else
		{
			dp[ i + 1 ] = min( dp[ i + 1 ] , dp[ i ] + 1 ) ;
		}
		j = i , k = 0 ;
		while ( j != 0 )
		{
			k = k * 10 + j % 10 ;
			j /= 10 ;
		}
		if ( dp[ k ] == 0 )
		{
			dp[ k ] = dp[ i ] + 1 ;
		}
		else
		{
			dp[ k ] = min( dp[ k ] , dp[ i ] + 1 ) ;
		}
	}
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		int n = in() ;
		cout << "Case #" << Case ++ << ": " << dp[ n ] << endl ;
	}
}


