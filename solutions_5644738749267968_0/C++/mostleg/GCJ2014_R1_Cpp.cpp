// GCJ2014_R1_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int T;
int N;
double girl[1024], boy[1024];

void init()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%lf", &girl[i]);
    }
    for (int i=0; i<N; i++) {
        scanf("%lf", &boy[i]);
    }
    sort(girl, girl+N);
    sort(boy, boy+N);
}

int war()
{
    int ret = 0;
    int p = 0;
    for (int i=0; i<N; i++) {
        while (p < N && girl[i] > boy[p]) {
            p++;
        }
        if (p == N) {
            break;
        }
        ret++;
        p++;
    }
    return N - ret;
}

int deceitful()
{
    int ret = 0;    
    int boy_high = N-1;
    int boy_low = 0;
    int girl_high = N-1;
    int girl_low = 0;
    while (girl_low <= girl_high) {
        if (girl[girl_low] > boy[boy_low]) {
            ret++;
            boy_low++;
            girl_low++;
        }
        else {
            boy_high--;
            girl_low++;
        }
    }
    return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\D-small-attempt0.in", "rb", stdin);
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\D-small-attempt0.out", "wb", stdout);
    scanf("%d",&T);
    for (int ca=1; ca<=T; ca++)
    {
        init();
        printf("Case #%d: %d %d\n", ca, deceitful(), war());
    }
	return 0;
}

