// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int r, c, w;

void init(){
	cin >> r >> c >> w;
}

void cal(){
	int ans;
	if ( c%w == 0 )
		ans = c/w-1+w + c/w*(r-1);
	else
		ans = c/w+w + c/w*(r-1);
	cout << ans << endl;
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

