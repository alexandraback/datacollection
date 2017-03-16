// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std; 

#define maxD 105
#define maxV 35

typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
typedef long long LL; 
typedef pair<int, int> PII; 

int T, C, D, V; 
int a[ maxD ]; 
bool can[ maxV ]; 

void init(){
	scanf( "%d%d%d", &C, &D, &V ); 
	for ( int i=0; i<D; i++ )
		scanf( "%d", &a[ i ] ); 
	memset( can, 0, sizeof( can ) ); 
	can[ 0 ]=true; 
	for ( int i=0; i<D; i++ ){
		for ( int v=V; v>=0; v-- ) if ( can[ v ] ){
			for ( int c=1; c<=C; c++ ){
				if ( v+c*a[ i ]<=V )
					can[ v+c*a[ i ] ]=true; 
			}
		}
	}
}

void cal(){
	int ans=0; 
	for ( int i=0; i<=V; i++ ){
		if ( can[ i ] ) continue; 
		ans++; 
		for ( int v=V; v>=0; v-- ){
			if ( !can[ v ] ) continue; 
			for ( int c=1; c<=C; c++ ){
				if ( v+c*i<=V )
					can[ v+c*i ]=true; 
			}
		}
	}
	cout << ans << endl; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "C-small-attempt0.in", "r", stdin ); 
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

