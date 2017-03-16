// =========================================================
// 
//       Filename:  A.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  04/27/2012 06:15:58 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  LI YAN (lyan), lyan@cs.ucr.edu
//        Company:  U of California Riverside
//      Copyright:  Copyright (c) 04/27/2012, LI YAN
// 
// =========================================================

#include <algorithm>
#include <cstdio>
using namespace std;

double prob[100000+5];
double cum[100000+5];

void solve(int tcase)
{
    int A, B; scanf("%d%d", &A, &B);
    for(int i=0; i<A; ++i) scanf("%lf", &prob[i]);
    cum[0]=prob[0];
    for(int i=1; i<A; ++i) cum[i]=cum[i-1]*prob[i];

    double ans=1+B+1; // gave up
    for(int i=0; i<A; ++i) {
        double curr=0;
        double p = cum[A-i-1];
        curr = i+i+B-A+1 + (1-p)*(B+1);
        ans=min(ans, curr);
    }
    printf("Case #%d: %.10lf\n", tcase, ans);
}

int main()
{
    int T; scanf("%d", &T);
    for(int t=1; t<=T; ++t) solve(t);
}
