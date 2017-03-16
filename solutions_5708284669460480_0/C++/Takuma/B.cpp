// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

#define maxS 105
#define maxL 105
#define maxK 105
int T, K, L, S, tot; 
int f[ maxS ]; 
char letters[ maxS ]; 
char word[ maxL ]; 
char type[ maxS ]; 

using namespace std; 

typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
typedef long long LL; 
typedef pair<int, int> PII; 

void init(  ){
	scanf( "%d%d%d", &K, &L, &S ); 
	scanf( "%s", letters ); 
	scanf( "%s", word ); 
}

void dfs( int pos ){
	if ( pos>=S ){
		int cnt=0; 
		for ( int i=0; i<S-L+1; i++ ){
			bool ok=true; 
			for ( int j=i; j<i+L; j++ ){
				if ( type[ j ]!=word[ j-i ] ){
					ok=false; 
					break; 
				}
			}
			if ( ok ) cnt++; 
		}
		f[ cnt ]++; 
		if ( cnt>tot )
			tot=cnt; 
		return; 
	}
	for ( int i=0; i<K; i++ ){
		type[ pos ]=letters[ i ]; 
		dfs( pos+1 ); 
	}
}

void cal(){
	memset( f, 0, sizeof( f ) ); 
	tot=0; 
	dfs( 0 ); 
	double ecnt=0; 
	double down=1.0; 
	for ( int i=1; i<=S; i++ )
		down*=K; 
	for ( int i=0; i<=S; i++ ){
		ecnt+=( tot-i )*f[ i ]; 
	}
	printf( "%.7lf\n", ecnt/down ); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "B-small-attempt0.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int t, i;
	scanf( "%d\n", &t );
	for ( i = 1; i <= t; i ++ ){
		init();
		cout << "Case #" << i << ": ";
		cal();
	}
	return 0;
}

