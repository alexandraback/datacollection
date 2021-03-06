//#include "stdafx.h"
//#include <time.h>
//#include "ryx_bignum.h"
/*基础题。
http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=3238&messageid=1&deep=0*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int local = 0;
double pre_speed, cur_speed;
double pre_re, cur_re;
int main()
{
	FILE *fi, *fo;
	fi = fopen("B-large.in", "r");
	fo = fopen("result.txt", "wb");
	int t, r, i;
	double c, f, x;
	double cost;
	if (local) scanf("%d", &t);
	else  fscanf(fi, "%d", &t);
	for(r=1; r<=t; r++) {
		if (local) scanf("%lf %lf %lf", &c, &f, &x);
		else  fscanf(fi, "%lf %lf %lf", &c, &f, &x);
		pre_speed = cur_speed = 2.0;
		pre_re = x/pre_speed;
		cost = 0;
		i = 1;
		while(1) {
			cur_speed = pre_speed+f;
			cost = cost+c/pre_speed;
			cur_re = cost+x/cur_speed;
			if (cur_re>=pre_re) break;
			else {
				pre_speed = cur_speed;
				pre_re    = cur_re;
				//i++;
			}
		}
		if (local) printf("Case #%d: %.7lf\n", r, pre_re);
		else  fprintf(fo, "Case #%d: %.7lf\n", r, pre_re);
	}
	return 0;
}