// a.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 200

int map[ MAXN ][ MAXN ], map_new[ MAXN ][ MAXN ];
int c[2][MAXN];
int n, m;

void init(){
	cin >> n >> m;
	for ( int i = 1; i <= n; i ++ )
		for ( int j = 1; j <= m; j ++ )
			cin >> map[i][j];
}

void paint(){
	int i, j;
	for ( i = 1; i <= n; i ++ )
		for ( j = 1; j <= m; j ++ )
			map_new[i][j] = MAXN;

	for ( i = 1; i <= n; i ++ )
		for ( j = 1; j <= m; j ++ )
			map_new[i][j] = map_new[i][j] > c[0][i] ? c[0][i] : map_new[i][j];
	
	for ( j = 1; j <= m; j ++ )
		for ( i = 1; i <= n; i ++ )
			map_new[i][j] = map_new[i][j] > c[1][j] ? c[1][j] : map_new[i][j];

	for ( i = 1; i <= n; i ++ )
		for ( j = 1; j <= m; j ++ )
			if ( map[i][j] != map_new[i][j] ){
				cout << "NO" << endl;
				return;
			}
	cout << "YES" << endl;
}

void cal(){
	int i, j, max_num;
	for ( i = 1; i <= n; i ++ ){
		max_num = 0;
		for ( j = 1; j <= m; j ++ )
			max_num = max_num < map[i][j] ? map[i][j] : max_num;
		c[0][i] = max_num;	
	}

	for ( j = 1; j <= m; j ++ ){
		max_num = 0;
		for ( i = 1; i <= n; i ++ )
			max_num = max_num < map[i][j] ? map[i][j] : max_num;
		c[1][j] = max_num;	
	}
	paint();
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

