// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 300

#define delta 1e-10

int s[ MAXN ], temp[ MAXN ];
int n, x, s1, s2;

void init(){
	cin >> n;
	x = 0;
	for ( int i = 1; i <= n; i ++ ){
		cin >> s[i];
		x += s[i];
		temp[i] = s[i];
	}
	sort( temp+1, temp+n+1 );
	s1 = temp[1];
	s2 = temp[2];
}

bool ok_( double y, int cur ){
	int i;
	double sum = 0.0, yi;
	double ss = s[cur]*1.0+x*1.0*y;
	for ( i = 1; i <= n; i ++ )
		if ( i != cur ){
			yi = (ss-s[i])/x;
			if ( yi>0 )
				sum += yi;
		}
	if ( sum + y > 1 )
		return true;
	else
		return false;
}

double find_( int cur ){
	double l = 0, r = 1.0, mid;
	while ( r-l > delta ){
		mid = ( r+l )/2;
		if ( ok_(mid,cur) )
			r = mid;
		else
			l = mid;
	}
	return (mid*100);
}

void cal(){
	int i;
	for ( i = 1; i <= n; i ++ ){
		printf( "%0.6lf",find_(i) );
		if ( i < n )
			cout << " ";
		else
			cout << endl;
	}

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

