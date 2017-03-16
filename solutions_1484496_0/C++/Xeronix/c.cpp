/*******************************************************************************************************************************************
* File Name   : c.cpp
* Development : Saturday 05 May 2012 09:47:59 PM IST
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
	int t, n, i, j ,k;
	int a[30], lim, sum;
	int T;

	scanf( "%d", &t ); 

	FOR( T,1,t ) {
		printf( "Case #%d:\n", T );

		scanf( "%d", &n );
		
		FOR( i,0,n-1 ) {
			scanf( "%d", &a[i] );
		}
		
		lim = ( 1 << n ) - 1;
		
		map< int, set<int> > m;
		map< int, set<int> >::iterator it;

		FOR( i,1,lim ) {
			set<int> s;
			sum = 0;
			
			FOR( j,0,n-1 ) {
				if( i & (1<<j) ) {
					s.insert(a[j]);
					sum += a[j];
				}	
			}

			if( ( it = m.find(sum) ) != m.end() && it->second != s ) {
				TR( s,ix ) {
					cout << *ix << " ";
				}

				puts(""); 

				TR( it->second, ix ) {
					cout << *ix << " ";
				}
				
				puts(""); 

				break;
			} else {
				m[sum] = s;
			}	
		}

		if( i == lim+1 ) {
			puts("IMPOSSIBLE");
		}
	}

	return 0;
}
