// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 1020

int a, b, k;
bool h[MAXN];


void init(){
	cin >> a >> b >> k;
	//memset( h, false, sizeof(h) );
}

void cal(){
	int i, j;
	long long ans = 0;
	for ( i = 0; i < a; i ++ )
		for ( j = 0; j < b; j ++ )
			if ( (i&j) < k ){
				//h[i&j] = true;
				ans ++;
			}
	cout << ans << endl;
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

