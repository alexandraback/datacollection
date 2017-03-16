// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 50

long long a_, b_, k_;
int a[ MAXN ], b[ MAXN ], k[ MAXN ], tmp[ MAXN ], sum[ MAXN ];
int tmp_l, max_l;


void convert( long long n ){
	int i = 0;
	memset( tmp, 0, sizeof(tmp) );
	while ( n > 0 ){
		i++;
		tmp[i] = n % 2;
		n /= 2;
	}
	tmp_l = i;
}

void init(){
	cin >> a_ >> b_ >> k_;
	a_ --;
	b_ --;
	k_ --;
	long long max_num = ( a_ > b_ ) ? a_:b_;
	max_num = ( max_num > k_ ) ? max_num:k_;
	
	max_l = (int)(log(max_num+0.0)/log(2.0))+1;
	
	int i;

	convert(b_);
	memset( b, 0, sizeof(b) );
	for ( i = 1; i <= tmp_l; i ++ )
		b[i+(max_l-tmp_l)] = tmp[tmp_l-i+1];

	convert(k_);
	memset( k, 0, sizeof(k) );
	for ( i = 1; i <= tmp_l; i ++ )
		k[i+(max_l-tmp_l)] = tmp[tmp_l-i+1];

}

void cal(){
	long long i, plus, minus;
	int j;
	for ( i = 1; i <= a_; i ++ ){
		convert(i);
		memset( a, 0, sizeof(a) );
		for ( j = 1; j <= tmp_l; j ++ )
			a[j+(max_l-tmp_l)] = tmp[tmp_l-j+1];

		plus = 1;
		minus = 0;
		memset( sum, 0, sizeof(sum) );
		sum[ max_l+1 ] = 1;
		for ( j = max_l; j >= 1; j -- ){
			if (!( k[j] == 1 && a[j] == 0 )){
				plus *= 2;
				sum[j] = sum[j+1]*2;
			}
			else
				sum[j] = sum[j+1];
		}

		for ( j = 1; j <= max_l; j ++ )
			if ( b[j] == 0 )
				minus += sum[j+1];
	}
	cout << plus-minus << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "in.txt", "r", stdin );
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

