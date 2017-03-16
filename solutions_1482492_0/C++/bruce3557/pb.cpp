//
//  pb.cpp
//  
//
//  Created by mac on 12/5/6.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

double D;
int N, A;

struct node {
    double t, x;
    node(){}
    node(double _t, double _x) {
        t = _t;
        x = _x;
    }
    void get() {
        scanf("%lf%lf",&t,&x);
    }
} S[1010];

int main() {
    int t, cases=0;
    
    scanf("%d",&t);
    while(t--) {
        scanf("%lf%d%d",&D,&N,&A);
        for(int i=0;i<N;++i)
            S[i].get();
        
        double v;
        double tv;
        if(N != 1) {
            v = (S[N-1].x-S[N-2].x)/(S[N-1].t-S[N-2].t);
            tv = (D-S[N-2].x)/v;
        }
        
        printf("Case #%d:\n", ++cases);
        while(A--) {
            double a;
            scanf("%lf", &a);
            double sv = (double)sqrt(2*D/a);
            //if(N == 1)  printf("%lf\n", sv);
            double mini = (sv > tv) ? sv : tv;
            printf("%lf\n", mini);
        }
    }
    
    return 0;
}
