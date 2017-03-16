/**
 *	Author	:
 *		Pan Yuchao
 *	Date	:
 *		2012-04-14
 *	Description	:
 *		Problem A. Speaking in Tongues
 *		Qualification Round 2012
 */
#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;
#define LS(t) ((t)<<1)
#define RS(t) (((t)<<1)+1)
#define MD(l,r) (((l)+(r))>>1)
#define PI 3.1415926535897932384626433832795
const string s1[] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi" ,
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" ,
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
} ;
const string s2[] = {
	"our language is impossible to understand" ,
	"there are twenty six factorial possibilities" ,
	"so it is okay if you want to just give up"
} ;
int TestCase , Case ;
char f[ 300 ] ;
bool b[ 300 ] ;
char s[ 10000000 ] ;

int main( int argc, char *argv[] )
{
	freopen( "input.txt" , "r" , stdin ) ;
	freopen( "output.txt" , "w" , stdout ) ;
	for ( int i = 0 ; i < 3 ; i ++ ) {
		for ( int j = 0 ; j < s1[ i ].size() ; j ++ ) {
			f[ s1[ i ][ j ] ] = s2[ i ][ j ] ;
		}
	}
	/*
	for ( int i = 'a' ; i <= 'z' ; i ++ )
	if ( f[ i ] ) {
		printf( "%c\n" , f[ i ] ) ;
		b[ f[ i ] ] = true ;
	} else {
		printf( "%c empty\n" , i ) ;
	}
	printf( "=========\n" ) ;
	for ( int i = 'a' ; i <= 'z' ; i ++ )
	if ( !b[ i ] ) {
		printf( "%c\n" , i ) ;
	}
	printf( "\n" ) ;
	*/
	f[ 'q' ] = 'z' ;
	f[ 'z' ] = 'q' ;
	scanf( "%d" , &TestCase ) ;
	gets( s ) ;
	while ( TestCase -- ) {
		gets( s ) ;
		printf( "Case #%d: " , ++ Case ) ;
		for ( int i = 0 ; s[ i ] ; i ++ ) {
			printf( "%c" , f[ s[ i ] ] ) ;
		}
		printf( "\n" ) ;
	}
	return 0;
}
