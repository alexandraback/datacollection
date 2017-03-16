// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 200

char s[MAXN];
int n;

void init(){
	scanf("%s %d\n", s, &n);
}

void cal(){
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
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "A-small-attempt0.in", "r", stdin );
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

