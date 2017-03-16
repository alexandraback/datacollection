// b.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 110

int sum[ MAXN ];
int n, s, p;

void init(){
	cin >> n >> s >> p;
	for ( int i = 1; i <= n; i ++ ){
		cin >> sum[ i ];
	}
	sort( sum+1, sum+n+1 ); 
}

void cal(){
	int i, num, ad, count = 0;
	for ( i = n; i >=1 ; i -- ){
		num = sum[i]/3;
		switch (sum[i]%3){
			case 0:
				ad = 0;
				break;
			case 1:
				ad = 1;
				break;
			case 2:
				ad = 1;
		}
		if ( num+ad< p && s > 0 && sum[i] > 0 && ( sum[i]%3 == 0 || sum[i]%3 == 2 ) ){
			s--;
			ad += 1;
		}
		if ( num + ad >= p ){
			count ++;
		}
	}
	cout << count << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "B-small-attempt1.in", "r", stdin );
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

