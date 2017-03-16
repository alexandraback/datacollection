/*
 * Author:  vawait
 * Created Time:  2014年05月04日 星期日 00时51分40秒
 * File Name: 1.cpp
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
typedef unsigned long long lint;
int n , m , k , N , M , K , a[100] , b[100] , c[100] ;
lint f[50][4];

void init()
{
	cin >> N >> M >> K;
	n = N - 1;
	m = M - 1;
	k = K;
	rep(i,1,40) {
		a[i] = n & 1;
		b[i] = m & 1;
		c[i] = k & 1;
		n >>= 1;
		m >>= 1;
		k >>= 1;
	}
	clr( f, 0 ); f[40][0] = 1;
}

lint dfs(int i,int j)
{
	lint k = ( (lint)1 << ( i - 1 ) ) , x , y , s = 0;
	if ( ( j & 1 ) || a[i] ) {
		if ( j & 1 ) x = k; else x = ( ( k - 1 ) & ( N - 1 ) ) + 1;
		if ( ( j & 2 ) || b[i] ) y = k; else y = ( ( k - 1 ) & ( M - 1 ) ) + 1;
		s += x * y;
	}
	if ( ( j & 2 ) || b[i] ) {
		if ( j & 2 ) y = k; else y = ( ( k - 1 ) & ( M - 1 ) ) + 1;
		if ( ( j & 1 ) || a[i] ) x = k; else x = ( ( k - 1 ) & ( N - 1 ) ) + 1;
		s += x * y;
	}
	if ( ( j & 1 ) || a[i] ) x = k; else x = ( ( k - 1 ) & ( N - 1 ) ) + 1;
	if ( ( j & 2 ) || b[i] ) y = k; else y = ( ( k - 1 ) & ( M - 1 ) ) + 1;
	s += x * y;
	return s;
}

void work()
{
	lint sum = 0;
	red(i,40,1)
		rep(j,0,3) if ( f[i][j] ) {
			if ( c[i] ) sum += f[i][j] * dfs(i,j);
			if ( !( j & 1 ) && a[i] < c[i] ) continue;
			if ( !( j & 2 ) && b[i] < c[i] ) continue;
			int k = j;
			if ( a[i] > c[i] ) k |= 1;
			if ( b[i] > c[i] ) k |= 2;
			f[i-1][k] += f[i][j];
			if ( !c[i] ) {
				if ( ( j & 1 ) || a[i] ) {
					if ( j & 1 ) k = 1; else k = 0;
					if ( ( j & 2 ) || b[i] ) k |= 2;
					f[i-1][k] +=  f[i][j];
				}
				if ( ( j & 2 ) || b[i] ) {
					if ( j & 2 ) k = 2; else k = 0;
					if ( ( j & 1 ) || a[i] ) k |= 1;
					f[i-1][k] +=  f[i][j];
				}
			}
		}
	cout << sum << endl;
}

int main()
{
	freopen("1.out","w",stdout);
	int t;
	cin >> t;
	rep(i,1,t) {
		printf("Case #%d: ",i);
		init();
		work();
	}
    return 0;
}
