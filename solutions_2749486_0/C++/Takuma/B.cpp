// B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 10000
#define MAXL 100
#define N 10
#define L 20

bool a[MAXN][2][MAXL];
int f[MAXN][MAXL];
int x, y,tt;
const char dis[2][2] = { {'E','W'}, {'N','S'} };

/*
bool update( bool &x1 ){
	if (!x1){
		x1 = true;
		return true;
	}
	return false;
}

void init_total(){
	int i, j, k, p, q, r;
	memset( a, false, sizeof(a) );
	
	a[N][0][0] = true;
	for ( r = 0; r <= L; r ++ ){
		for ( i = 0; i <= 2*N; i ++ )
			a[i][(r+1)%2][r] = false;
		
		//a[N][r%2][r] = true;
		//f[N][r]=N;
		for ( k = r+1; k <= N; k ++ ){
			p = k%2;
			q = 1-p;
			for ( i = -N; i <= N*2; i ++ ){
				j = i+N;
				if ( j == 7 ){
					int aa = 1;
				}
				if ( a[j][q][r] ){
					if ( j+k <= N*2 )
						if (update( a[j+k][p][r] ))
							f[j+k][r] = j;
					if ( j-k >= 0 )
						if (update( a[j-k][p][r] ))
							f[j-k][r] = j;
				}
			}
		}
	}
}
*/

void init(){
	cin >> x >> y;
}

void pro( int x, int d ){
	int flag, s = 0, p = tt+1;
	if ( x > 0 )
		flag = 0;
	else{
		flag = 1;
		x = -x;
	}

	while ( s+p <= x ){
		s += p;
		p += 1;
		tt ++;
		cout << dis[d][flag];
	}

	x = x-s;
	while ( x > 0 ){
		x--;
		tt += 2;
		cout << dis[d][1-flag] << dis[d][flag];
	}
}

void cal(){
	tt = 0;
	pro(x, 0);
	pro(y, 1);
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "B-small-attempt0.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	//init_total();
	int t, i;
	scanf( "%d\n", &t );
	for ( i = 1; i <= t; i ++ ){
		init();
		cout << "Case #" << i << ": ";
		cal();
	}
	return 0;
}

