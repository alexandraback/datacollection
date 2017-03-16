/*******************************************************************************************************************************************
* File Name   : a2.cpp
* Development : Saturday 05 May 2012 11:23:21 PM IST
* Author      : Xeronix
*******************************************************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <utility>
#include <cctype>
#include <list>
#include <limits.h>
#include <signal.h>
#include <time.h>
#include <map>
#include <set>
#include <float.h>

//#include ".prettyprint.hpp"

#define TR(c, i) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++ ) 
#define FOR(i, a, b) for ( i = a; i <= b; i++ )
#define ROF(i, a, b) for ( i = a; i >= b; i-- )
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort( ALL(v) )
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) < (0) ? (a)*(-1) : (a))
#define SWAP(a, b) {typeof(a) T; T=a; a=b; b=T;}
#define SET(x,a) memset(x,a,sizeof(x))

//#define LIM
#ifdef LIM
	int S, D, Y, O;
	char *inp, *out, *ipos, *opos, DIG[30];
	#define FRMI inp=( char * )malloc( LIM*sizeof( char ) );fread_unlocked( inp,1,LIM,stdin );ipos=inp;
	#define FWM out=( char * )malloc( LIM*sizeof( char ) );opos=out;
	#define FWO fwrite_unlocked( out,opos-out,1,stdout );
        #define GETI(n) n=0;while(*ipos<33){ipos++;}if(*ipos=='-'){S=-1;ipos++;}else{S=1;}while(*ipos>='0'){n=10*n+(*ipos-'0');ipos++;}n*=S;
	#define PUTI(O) n=O;D=0;if(n<0){*opos++='-';n*=-1;}if(!n)*opos++='0';else{while(n){Y=n/10;DIG[D++]=n-Y*10+'0';n=Y;}\
	while(D--)*opos++=DIG[D];}
	#define PUTC(c) *opos++=c;
#endif

using namespace std;

int main()
{	
	int i, j, k, T;
	int t, n, a[300], sum, r, x;

	scanf( "%d", &t ); 
	
	FOR( T,1,t ) {
		scanf( "%d", &n ); 
		
		sum = 0;

		FOR( i,0,n-1 ) {
			scanf( "%d", &a[i] );
			sum += a[i];
		}
		
		printf( "Case #%d: ", T );

		FOR( j,0,n-1 ) {
			FOR( i,0,sum ) {
				x = a[j] + i;
				r = sum-i;
			
				FOR( k,0,n-1 ) {
					if( k != j && x > a[k] ) {
						if( r >= (x-a[k]) ) {
							r -= (x-a[k]);
							if( r <= 0 ) {
								break;
							}
						} else {
							break;
						}
					}
				}
				
				if( k != n ) {
					printf( "%.10lf ", (i/(sum+0.0)*100.0 ) );
					break;
				}
			}

			if( i == sum+1 ) {
				printf( "%.10lf ", 100.0 );
			}
		}

		puts("");
	}	

	return 0;
}
