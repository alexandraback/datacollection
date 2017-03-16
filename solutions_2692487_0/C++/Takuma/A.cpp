// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 110

int m, n;
int a[MAXN];

void init(){
	cin >> m >> n;
	for ( int i = 1; i <= n; i ++ ){
		cin >> a[i];
	}
	sort( a+1, a+n+1 );
}

void cal(){
	int i, ans = 0, res, t, mm, min_ans = MAXN;
	for ( i = 1; i <= n; i ++ ){
		res = n-i+1;
		if ( a[i] < m )
			m += a[i];
		else{
			t = 0;
			mm = m;
			while ( mm <= a[i] && t <= n ){
				t++;
				mm += mm-1;
			}
			if ( t >= res ){
				ans += res;
				break;
			}
			else{
				min_ans = min( min_ans, ans+res );
				m = mm+a[i];
				ans += t;
			}
		}
	}
	ans = min( min_ans, ans );
	cout << ans << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "A-small-attempt1.in", "r", stdin );
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

