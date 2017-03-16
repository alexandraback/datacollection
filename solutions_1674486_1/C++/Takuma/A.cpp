// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1100
#define MAXM 20

int n;
int map[ MAXN ][ MAXM ];
int m[ MAXN ];
bool con[ MAXN ][ MAXN ];

void init(){
	cin >> n;
	int i, j, k;
	memset( con, false, sizeof( con ) );
	for ( i = 1; i <= n; i ++ ){
		cin >> m[i];
		for ( j = 1; j <= m[i]; j ++ ){
			scanf( "%d", &map[i][j] );
			con[ i ][map[i][j] ] = true;
		}
		con[i][i] = true;
	}

	for ( k = 1; k <= n; k ++ )
		for ( i = 1; i <= n; i ++ )
			for ( j = 1; j <= n; j ++ )
				if ( con[i][k] && con[k][j] )
					con[i][j] = true;
}

void cal(){
	int i, j, k, ki;
	bool flag;
	for ( i = 1; i <= n; i ++ )
		for ( j = 1; j <= n; j ++ )
			if ( i!=j && con[i][j]){
				flag = false;
				for ( ki = 1; ki <= m[i]; ki ++ ){
					k = map[i][ki];
					if ( k!=i && con[k][j] )
						if ( !flag )
							flag = true;
						else{
							cout << "Yes" << endl;
							return;
						}
				}
			}
	cout << "No" << endl;
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

