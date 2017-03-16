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
struct dot
{
	string s ;
	int x , y ;
} now , next ;
int main ()
{
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		int X=in() , Y=in() ;
		cout << "Case #" << Case ++ << ": " ;
		if ( X > 0 )
		{
			for ( int i = 0 ; i < X ; i ++ )
			{
				printf( "WE" ) ;
			}
		}
		if ( X < 0 )
		{
			X = -X ;
			for ( int i = 0 ; i < X ; i ++ )
			{
				printf( "EW" ) ;
			}
		}
		if ( Y > 0 )
		{
			for ( int i = 0 ; i < Y ; i ++ )
			{
				printf( "SN" ) ;
			}
		}
		if ( Y < 0 )
		{
			Y = -Y ;
			for ( int i = 0 ; i < Y ; i ++ )
			{
				printf( "NS" ) ;
			}
		}
		puts( "" ) ;
	}
}


