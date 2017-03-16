// C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 200

struct node{
	int type;
	long long num, rest;
};

int n, m;
node a[ MAXN ],b[ MAXN ];
int f[5];
long long max_;

void init(){
	cin >> n >> m;
	int i;
	for ( i = 1; i <= n; i ++ )
		cin >> a[i].num >> a[i].type;
	for ( i = 1; i <= m; i ++ )
		cin >> b[i].num >> b[i].type;
}

void check(){
	int i, j;
	long long r, sum = 0;
	f[n] = m;
	b[f[0]].rest = b[f[0]].num;
	b[f[1]].rest = b[f[1]].num;
	b[f[2]].rest = b[f[2]].num;
	b[f[3]].rest = b[f[3]].num;
	for ( i = 1; i <= n; i ++ ){
		r = a[i].num;
		for ( j = f[i-1]; j <= f[i]; j ++ ){
			if ( r > 0 && a[i].type == b[j].type ){
				if ( j == f[i-1] ){
					if ( b[j].rest >= r ){
						if ( j == f[i] ){
							b[j].rest -= r;
						}
						sum += r;
						r = 0;
					}
					else{
						if ( j == f[i] ){
							b[j].rest = 0;
						}
						sum += b[j].rest;
						r -= b[j].rest;
					}
				}
				else{
					if ( b[j].num >= r ){
						if ( j == f[i] ){
							b[j].rest -= r;
						}
						sum += r;
						r = 0;
					}
					else{
						if ( j == f[i] ){
							b[j].rest = 0;
						}
						sum += b[j].num;
						r -= b[j].num;
					}
				}
			}
		}
	}
	if ( sum > max_ )
		max_ = sum;
}

void try_( int k ){
	int i;
	for ( i = f[k-1]; i <= m; i ++ ){
		f[ k ] = i;
		if ( k == n-1 )
			check();
		else
			try_(k+1);
	}
}
void cal(){
	max_ = 0;
	f[0] = 1;
	if ( n == 1 )
		check();
	else
		try_(1);
	cout << max_ << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "C-small-attempt1.in", "r", stdin );
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

