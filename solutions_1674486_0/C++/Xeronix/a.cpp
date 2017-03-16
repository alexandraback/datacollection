/*******************************************************************************************************************************************
* File Name   : a.cpp
* Development : Sunday 06 May 2012 02:41:31 PM IST
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
	#define PUTI(n) O=n;D=0;if(O<0){*opos++='-';O*=-1;}if(!O)*opos++='0';else{while(O){Y=O/10;DIG[D++]=O-Y*10+'0';O=Y;}\
	while(D--)*opos++=DIG[D];}
	#define PUTC(c) *opos++=c;
#endif

using namespace std;

int n;
bool *mat[1010];
bool *visit, fc;

void dfs( int a )
{
	visit[a] = true;
	
	int i, j;

	FOR( i,1,n ) {
		if( i != a && mat[a][i] ) {
			if( visit[i] ) {
				fc = true;
		       		return;
			} else {
				dfs(i);
			}		
		}

		if( fc ) {
			return;
		}
	}
}

int main()
{	
	int t, T, m, v;
	int i, j;

	scanf( "%d", &t ); 

	FOR( T,1,t ) {
		scanf( "%d", &n ); 
		
		FOR( i,1,n ) {
			mat[i] = ( bool * )calloc( n+1, sizeof( bool ) );
			scanf( "%d", &m );

			FOR( j,1,m ) {
				scanf( "%d", &v );
				mat[i][v] = true;
			}
		}

		/*
		FOR( i,1,n ) {
			FOR( j,1,n ) {
				cout << mat[i][j] << " ";
			}puts(""); 
		}*/

		printf( "Case #%d: ", T );

		FOR( i,1,n ) {
			visit = ( bool * )calloc( n+1, sizeof( bool ) );
			fc = false;

			dfs(i);	
			free(visit);	
			
			if( fc ) {
				puts("Yes");
				break;
			}
		}

		if( !fc ) {
			puts("No");
		}
	}

	return 0;
}
