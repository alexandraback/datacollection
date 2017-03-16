// c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define LOG(a) (int)log10(a*1.0)
#define POW(a) (int)pow(10,a*1.0)
#define MAXN 1000

const int ten[6] = { 10, 100, 1000, 10000, 100000, 1000000 };

int a, b;
int sum;
int okm[ MAXN ];

void init(){
	scanf( "%d%d", &a, &b );
}

void cal(){
	int n, m, j, total;
	sum = 0;
	for ( n = a; n <= b; n ++ ){
		total = 0;
		memset( okm, 0, sizeof(okm) );
		for ( j = 0; j < 6 && ten[j] < n; j ++ ){
			m = n/ten[j] + n%ten[j]*POW(LOG(n/ten[j])+1);
			if ( m > n && m <= b ){
				okm[ ++total ] = m;
			}
		}
		sort( okm+1, okm+total+1 );
		for ( int i = 1; i <= total; i ++ ){
			if ( okm[i] != okm[i+1] ){
				//cout << n << " " << okm[i] << endl;
				sum ++;
			}
		}
	}
	cout << sum << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "C-large.in", "r", stdin );
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

