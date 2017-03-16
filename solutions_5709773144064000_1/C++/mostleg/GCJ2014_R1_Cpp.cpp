// GCJ2014_R1_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int T;

double solve_it()
{
    double C,F,X;

    scanf("%lf %lf %lf", &C, &F, &X);
    int N = int( (F * (X - C) / C - 2) / F + 1);

    if (N <= 0) {
        return X / 2;
    }
    double ret = 0;
    for (int i=0; i<N; i++) {
        ret += C / (2 + i*F);
    }
    ret += X / (2 + N*F);
    return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\B-large.in", "rb", stdin);
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\B-large.out", "wb", stdout);
    scanf("%d",&T);
    for (int ca=1; ca<=T; ca++)
    {
        printf("Case #%d: %.7lf\n", ca, solve_it());
    }
	return 0;
}

