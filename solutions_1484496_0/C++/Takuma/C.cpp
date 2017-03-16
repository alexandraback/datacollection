// C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100

struct node{
	int sum;
	int pick;
};

int s[ MAXN ], a[ MAXN ];
int n;
vector<node> p;

void init(){
	cin >> n;
	for ( int i = 1; i <= n; i ++ )
		cin >> s[i];
}

void check(){
	int i;
	node pi;
	pi.sum = 0;
	pi.pick = 0;
	for ( i = 1; i <= n; i ++ ){
		if ( a[i] == 1 ){
			pi.sum += s[i];
			pi.pick |= (1 << i);
		}
	}
	p.push_back(pi);
}

void try_( int k ){
	int i;
	for ( i = 0; i <= 1; i ++ ){
		a[ k ] = i;
		if ( k == n ){
			check();
		}
		else
			try_(k+1);
	}
		
}

bool sort_p( node p1, node p2 ){
	return ( p1.sum < p2.sum );
}

void print_(){
	sort(p.begin(),p.end(),sort_p);
	int i;
	bool flag = false;
	for ( i = 0; i < p.size()-1; i ++ )
		if ( p[i].sum == p[i+1].sum ){
			flag = true;
			break;
		}

	cout << endl;
	if ( !flag )
		cout << "Impossible" << endl;
	else{
		int j;
		for ( j = 1; j <= n; j ++ )
			if ( ( (1<<j) & p[i].pick ) > 0 )
				cout << s[j] << " ";
		cout << endl;
		for ( j = 1; j <= n; j ++ )
			if ( ( (1<<j) & p[i+1].pick ) > 0 )
				cout << s[j] << " ";
		cout << endl;
	}
}

void cal(){
	p.clear();
	try_(1);
	print_();
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "C-small-attempt0.in", "r", stdin );
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

