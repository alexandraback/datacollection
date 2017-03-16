// a.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

const int n=4;
char s[n+2][n+2];
bool empty;

void init(){
	int i, j;
	empty = false;
	for ( i = 1; i <= n; i ++ ){
		for ( j = 1; j <= n; j ++ ){
			scanf( "%c", &s[i][j] );
			if ( s[i][j] == '.' )
				empty = true;
		}
		scanf("\n");
	}
	scanf("\n");
}

bool check( char  c ){
	int i, j;
	bool flag;
	
	//row
	for ( i = 1; i <= n; i ++ ){
		flag = true;
		for ( j = 1; j <= n; j ++ )
			if ( s[i][j] != c && s[i][j] != 'T' )
				flag = false;
		if ( flag )
			return true;
	}

	//column
	for ( j = 1; j <= n; j ++ ){
		flag = true;
		for ( i = 1; i <= n; i ++ )
			if ( s[i][j] != c && s[i][j] != 'T' )
				flag = false;
		if ( flag )
			return true;
	}

	//diagonal
	flag = true;
	for ( i = 1; i <= n; i ++ )
		if ( s[i][i] != c && s[i][i] != 'T' )
			flag = false;
	if ( flag )
			return true;

	flag = true;
	for ( i = 1; i <= n; i ++ )
		if ( s[i][n-i+1] != c && s[i][n-i+1] != 'T' )
			flag = false;
	if ( flag )
			return true;
	
	return false;
}

void cal(){
	if ( check('X') ){
		cout << "X won" << endl;
		return;
	}
	if ( check('O') ){
		cout << "O won" << endl;
		return;
	}
	if ( empty ){
		cout << "Game has not completed" << endl;
		return;
	}
	cout << "Draw" << endl;
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

