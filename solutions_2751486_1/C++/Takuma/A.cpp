// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 1000010

char s[MAXN];
int n;
int opt[MAXN], u[MAXN];

bool con( char c ){
	if ( c != 'a' && c!= 'e' && c!= 'i' && c!= 'o' && c!= 'u' )
		return true;
	return false;
}

void init(){
	scanf("%s %d\n", s, &n);
	
	
	int i, l = strlen(s);
	if ( con(s[l-1]) )
		u[ l-1 ] = 1;
	else
		u[ l-1 ] = -1;
	for ( i = l-2; i >= 0; i -- )
		if ( !con(s[i]) ){
			u[i] = -1;
		}
		else{
			if ( u[i+1] > 0 )
				u[i] = u[i+1]+1;
			else
				u[i] = 1;
		}
	
	if ( u[l-1] >= n )
		opt[l-1] = l-1;
	else
		opt[l-1] = -1;

	for ( i = l-2; i >= 0; i -- )
		if ( u[i] >= n )
			opt[i] = i;
		else
			opt[i] = opt[i+1];

}

void cal(){
	int i, l = strlen(s);
	long long ans = 0;
	for ( i = 0; i < l; i ++ )
		if ( opt[i] !=-1 )
			if ( l-opt[i]-n+1 > 0 )
				ans += l-opt[i]-n+1;

	cout << ans << endl;
	/*
	int i, j, k, l = strlen(s);
	int ans = 0, c;
	for ( i = 0; i < l; i ++ )
		for ( j = i; j < l; j ++ ){
			c = 0;
			for ( k = i; k <= j; k ++ ){
				if ( s[k] != 'a' && s[k]!= 'e' && s[k]!= 'i' && s[k]!= 'o' && s[k]!= 'u' )
					c++;
				else
					c = 0;
				if ( c >= n ){
					ans ++;
					break;
				}
			}
		}
	cout << ans << endl;
	*/
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "A-large.in", "r", stdin );
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

