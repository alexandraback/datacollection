#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

#define MAXN 10000050

int good[MAXN] ;

bool check( long long x )
{
	string xx ;
	while( x != 0 )
	{
		xx += ( ( x%10 ) + '0' ) ;
		x /= 10 ;
	}
	int size = xx.size() ;
	bool flag = true;
	for( int i = 0 ; i < size/2 ; i ++ )
	{
		if( xx[i] != xx[size-1-i] )
		{
			flag = false ;
			break;
		}
	}
	return flag ;
}

int main()
{	
	freopen("D:\\C.in","r",stdin);
	freopen("D:\\C.out","w",stdout);
	int cas ;
    scanf("%d",&cas);
	good[1] = 1 ;
	for( long long i = 2 ; i < MAXN ; i ++ )
	{
		if( check(i) == false )
		{
			good[i] = good[i-1];
			continue;
		}
		long long x = i * i ;
		good[i] = good[i-1]+check(x) ;
	}
	for( int c = 1 ; c <= cas ; c ++ )
	{
		long long A,B;
		cin >> A >> B ;
		long long a,b;
		a = sqrt(A)+2 ;
		b = sqrt(B)+2 ;
		while(a*a >= A) a--;
		while(b*b > B) b-- ;
		printf("Case #%d: %d\n",c,good[b]-good[a]);
	}
	return 0 ;
}