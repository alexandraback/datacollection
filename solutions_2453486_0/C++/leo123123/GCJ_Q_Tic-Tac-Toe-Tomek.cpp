#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

char m[10][10] ;

int check()
{
	int flag = 0 ;
	for( int i = 0 ; i < 4 ; i ++ )
	{
		for( int j = 0 ; j < 4 ; j ++ )
		{
			if(m[i][j] == '.')
			{
				flag = 1 ;
			}
		}
	}
	int X,O,T ;
	for( int i = 0 ;  i < 10 ; i ++ )
	{
		X = 0 ;
		O = 0 ;
		T = 0 ;
		int one , two ;
		for( int j = 0 ; j < 4 ; j ++ )
		{
			if( i < 4 )
			{
				one = i ; 
				two = j ;
			}
			else if( i < 8 )
			{
				one = j ; 
				two = (i%4) ;
			}
			else if( i == 8 )
			{
				one = j ;
				two = j ;
			}
			else if( i == 9 )
			{
				one = 3-j;
				two = j ;
			}
			if( m[one][two] == 'X')
			{
				X++;
			}
			if( m[one][two] == 'O' )
			{
				O++;
			}
			if( m[one][two] == 'T' )
			{
				T ++ ;
			}
		}
		if( X+T >= 4 )
		{
			return 1 ;
		}
		if( T+O >= 4 )
		{
			return 2 ;
		}
	}
	if( flag == 1 )
	{
		return 3 ;
	}
	return 0 ;
}

int main()
{
	freopen("D:\\input.txt","r",stdin);
	freopen("D:\\output.txt","w",stdout);
	int cas;
	scanf("%d",&cas);
	for( int c = 1 ; c <= cas ; c ++ )
	{
		for( int i = 0 ; i < 4 ; i ++ )
		{
			scanf("%s",&m[i]);
		}
		string xx ;
		getline(cin,xx);
		if( check() == 0 )
		{
			printf("Case #%d: Draw\n",c);
		}
		if( check() == 1 )
		{
			printf("Case #%d: X won\n",c);
		}
		if( check() == 2 )
		{
			printf("Case #%d: O won\n",c);
		}
		if( check() == 3 )
		{
			printf("Case #%d: Game has not completed\n",c);
		}
	}
	return 0 ;
}