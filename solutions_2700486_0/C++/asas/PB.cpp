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
int main ()
{
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		int M = in() , x = in() , y = in() ;
		if ( x < 0 ) x *= -1 ;
		int n = x + y ;
		int low = n / 2 * ( n - 1 ) ;
		int high = ( n + 2 ) / 2 * ( n + 1 ) ;
		if ( M <= low )
		{
			printf( "Case #%d: 0.0\n" , Case ++ ) ;
		}else
		if ( M >= high )
		{
			printf( "Case #%d: 1.0\n" , Case ++ ) ;
		}
		else
		{
			int ball = M - low ;
			double s = 0 , m = 0 , tmp ;
			for ( int i = n ; i > y ; i -- )
			{
				if ( ball - i < 0 ) continue ;
				if ( ball - i > n ) break ;
				tmp = 1 ;
				for ( int j = ball , limit = max( i , ball - i ) ; j > limit ; j -- )
				{
					tmp *= j ;
				}
				for ( int j = min( i , ball - i ) ; j ; j -- )
				{
					tmp /= j ;
				}
				m += tmp ;
				s += tmp ;
			}
			for ( int i = y ; i >= 0 ; i -- )
			{
				if ( ball - i < 0 ) continue ;
				if ( ball - i > n ) break ;
				tmp = 1 ;
				for ( int j = ball , limit = max( i , ball - i ) ; j > limit ; j -- )
				{
					tmp *= j ;
				}
				for ( int j = min( i , ball - i ) ; j ; j -- )
				{
					tmp /= j ;
				}
				m += tmp ;
			}
			printf( "Case #%d: %.10lf\n" , Case ++ , s / m ) ;
			//printf( "y=%d, ball=%d\n" , y , ball ) ;
			//printf( "%.6lf %.6lf\n" , s , m ) ;
		}
	}
}


