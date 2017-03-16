// a.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define SQRT(a) (long long)sqrt( (double)(a) )
#define LOG(a) log( (double)(a) )
#define DIGS(a) (int)floor(( LOG(a)/LOG(10.0) ))+1

#define MAXN 20

long long a, b;
int num[MAXN];


void init(){
	cin >> a >> b;
}

int ten( int d ){
	int r = 1;
	for ( int i = 1; i <= d; i ++ ){
		r *= 10;
	}
	return r;
}

int pro_fair( int half, int digs){
	int h = half, k = half;
	if ( digs % 2 > 0 )
		h /= 10;
	while ( h > 0 ){
		k = k*10+h%10;
		h /= 10;
	}
	return k;
}

bool check_square( long long s, long long n ){
	if ( s > n )
		return false;
	int l = 0, i, j;
	while ( s > 0 ){
		l++;
		num[l] = s%10;
		s /= 10;
	}
	i = 1;
	j = l;
	while ( i < j ){
		if ( num[i] != num[j] )
			return false;
		i++;
		j--;
	}
	return true;
}

int pro_sqr( int m, long long n ){
	int digs = DIGS(m);
	int d, half, fair, result = 0;
	long long s;

	for ( fair = 1; fair <= 9; fair ++ )
		if ( fair <= m ){
			s = fair*fair;
			if (check_square(s, n)){
				//cout << fair << " " << s << endl;
				result++;
			}
		}

	for ( d = 2; d <= digs; d ++ )
		for ( half = ten((d+1)/2-1); half < ten((d+1)/2); half++ ){
			fair = pro_fair(half, d);
			if ( fair <= m ){
				s = (long long)fair*fair;
				if (check_square(s, n)){
					//cout << fair << " " << s << endl;
					result++;
				}
			}
		}
	return result;
}

int pro( long long n ){
	if ( n == 0 )
		return 0;
	long long m = SQRT( n );
	while ( (m+1)*(m+1) <= n )
		m++;
	return( pro_sqr((int)m, n ) );
}

void cal(){
	int ans = pro(b) - pro(a-1);
	cout << ans << endl;
}



int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "C-large-1.in", "r", stdin );
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

