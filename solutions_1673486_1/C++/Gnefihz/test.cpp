// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#define N 110000
double p[N];
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("t.in", "r", stdin);
	freopen("t.out", "w", stdout);
	int cas, a, b;

	scanf("%d\n", &cas);
	int cas_no = 1;
	while(cas -- ){
		scanf("%d %d\n", &a, &b);
		for(int i = 0; i < a; i ++){
			scanf("%lf", &p[i]);
			if(i > 0)
				p[i] *= p[i - 1];
		}

		double ky = b + 2;
		double kx;
		
		for(int i = 0; i < a ; i ++){
			kx = (b - (a - i) + 1) + 1.0 *(1 - p[ a - 1 - i]) *(b + 1) + i; 
			//printf("%lf\n", (1 - p[ a - 1 - i]));
			if(kx < ky){
				ky = kx;
			}
		}
		//double re = 3.14;
		printf("Case #%d: %0.6f\n", cas_no, ky);
		cas_no ++;
	}
	//scanf("\n");
	return 0;
}

