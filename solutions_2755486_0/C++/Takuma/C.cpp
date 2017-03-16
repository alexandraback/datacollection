// C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>


#define maxn ( 105 )
#define BASE ( 500 )
using namespace std;

struct Tnode{
	int day, west, east, s;
}attack[ maxn ];

int wall[ 2005 ], M, N, day, Ni, Wi, Ei, Si, delta_d, delta_p, delta_s, now, testcase;

bool cmp( Tnode a, Tnode b ){
	return a.day<b.day;
}

int _tmain( int argc,  _TCHAR* argv[  ] ){
	freopen( "C-small-attempt0.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	
	scanf( "%d", &testcase );
	for ( now=1;testcase--;now++ ){
		scanf( "%d", &N );
		printf( "Case #%d: ", now );
		M=0;
		for ( int i=0;i<N;i++ ){
			scanf( "%d%d%d%d%d%d%d%d", &day, &Ni, &Wi, &Ei, &Si, &delta_d, &delta_p, &delta_s );
			for ( int j=0;j<Ni;j++ ){
				attack[ M ].day=day;
				attack[ M ].west=Wi;
				attack[ M ].east=Ei;
				attack[ M ].s=Si;
				day+=delta_d;
				Wi+=delta_p;
				Ei+=delta_p;
				Si+=delta_s;
				M++;
			}
		}
		sort( attack, attack+M, cmp );
		memset( wall, 0, sizeof( wall ) );
		int res=0;
		for ( int i=0, prei=-1;i<M;i++ ){
			bool ok=false;
			for ( int j=attack[ i ].west;j<attack[ i ].east && !ok;j++ )
				if ( wall[ j+BASE ]<attack[ i ].s ) ok=true;
			if ( ok )
				res++;
			if ( i==M-1 || attack[ i ].day!=attack[ i+1 ].day ){
				for ( int j=prei+1;j<=i;j++ ){
					for ( int k=attack[ j ].west;k<attack[ j ].east;k++ )
						if ( wall[ k+BASE ]<attack[ j ].s )
							wall[ k+BASE ]=attack[ j ].s;
				}
				prei=i;
			}
		}
		printf( "%d\n", res );
	}
	return 0;
}
