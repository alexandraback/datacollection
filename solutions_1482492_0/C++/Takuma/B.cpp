// B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define SQR(a) ((a)*(a))

#define MAXN 2100

int n, m;
double t[ MAXN ], x[ MAXN ];
double d, a;

void cal(){
	

	
	double v = (x[2]-x[1])/(t[2]-t[1]);
	double t;

	if ( n == 1 ){
		t = sqrt( 2*d/a );
		printf("%0.8lf\n",t);
		return;
	}
	/*
	if ( 1-2*a*x[1] < 0 ){
		t = sqrt( 2*d/a );
	}
	else{
	*/
		/*
		double t1 = ( v + sqrt(1-2*a*x[1]) ) / (a);
		double t2 = ( v + sqrt(1-2*a*x[1]) ) / (a);
		double t = 0;
		if ( t1 > 0 )
			t = t1;
		*/
		

		double t1 = ( v + sqrt(SQR(v)+2*a*x[1]) ) / (a);
		//double t2 = ( v - sqrt(SQR(v)+2*a*x[1]) ) / (a);
		double s = 0.5*a*SQR(t1), t3 = 0;
		

		if ( s >=d ){
			t = sqrt( 2*d/a );
		}
		else{
			t = (d-s)/v + t1;
		}
	//}
	printf("%0.8lf\n",t);
}

void init(){
	cin >> d >> n >> m;
	int i;
	for ( i = 1; i <= n; i ++ ){
		cin >> t[i] >> x[i];
	}
	for ( i = 1; i <= m; i ++ ){
		cin >> a;
		cal();
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "B-small-attempt1.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int t, i;
	scanf( "%d\n", &t );
	for ( i = 1; i <= t; i ++ ){
		cout << "Case #" << i << ": " << endl;
		init();
		//cal();
	}
	return 0;
}

