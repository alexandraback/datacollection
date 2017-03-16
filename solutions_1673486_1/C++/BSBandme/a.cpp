/*
 * a.cpp
 *
 *  Created on: 2012-4-28
 *      Author: Administrator
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double p[101000];
	int ncase, have, all;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &ncase);
	for(int i1 = 0; i1 < ncase; i1++){
		scanf("%d%d", &have, &all);
		for(int i = 0; i < have; i++) scanf("%lf", &p[i]);
		double ans = 2 + all;
		double p1 = 1;
		for(int i = 0; i < have; i++){
			p1 *= p[i];
			double n1 = have - (i + 1) + all - (i + 1) + 1;
			double ans1 = n1 * p1 + (1 - p1) * (n1 + all + 1);
			if(ans1 < ans) ans = ans1;
		}
		printf("Case #%d: %.6lf\n", i1 + 1, ans);
	}

	return 0;
}



