//============================================================================
// Name        : GCJ2013-Round1C.cpp
// Author      : Anmol Ahuja
//============================================================================


//Q1

#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstdlib>

//#define _USE_MATH_DEFINES
using namespace std;


#define TYPE int

#define FORI(a,b) for( int I = (a); I<(b); ++I )
#define FORIE(a,b) for( int I = (a); I<=(b); ++I )
#define SMALLER(a,b) (((a)<(b))?(a):(b))
#define GREATER(a,b) (((a)>(b))?(a):(b))

#define TYPE int
#define MAX 100

TYPE consec[MAX];

bool isVowel( char v )
{
	if( v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u' )
		return true;
	return false;
}

TYPE n_value( char *name, int n )
{
	TYPE size = strlen( name );
	if( n == 0 )
	{
		return ( size*(size+1) )/2;
	}
	TYPE consecNum = 0, num = 0, j=0;
	for( TYPE i=0; i<size-n+1; ++i )
	{
		for( j=0; j< n; ++j )
		{
			if( isVowel(name[i+j]) )
			{
				i = i+j;
				break;
			}
		}
		if( j==n )
			consec[consecNum++] = i;
	}

	for( TYPE i=0; i<consecNum; ++i )
	{
		if( i == 0 )
		{
			num = num + ( consec[i] ) * ( size-consec[i] - n + 1 ) + 1;
			num = num + size-consec[i] - n;
		}
		else
		{
			num = num + ( consec[i] - consec[i-1] - 1 ) * ( size-consec[i] - n + 1 )  + size - consec[i] - n + 1;
		}
	}
	return num;
}
int main() {
	int T, x;
	scanf( "%d", &T );
	char name[MAX];
	int n;
	for( x=1; x<=T; ++x)
	{
		scanf("%s %d", name, &n);
		cout<<"Case #"<<x<<": "<< n_value( name, n ) <<"\n";
	}
	return 0;
}
