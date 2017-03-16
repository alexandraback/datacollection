#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

int kasus;
double C,F,X;

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%lf %lf %lf",&C,&F,&X);
        int n = (int)(floor((X*F-2.0*C)/(C*F)) + 0.001);
        if (n < 0) n = 0;
        
        double cps = 2.0;
        double jawab = 0.0;
        for (int i=0;i<n;++i) {
            jawab += C/cps;
            cps += F;
        }
        
        jawab += X/cps;
        printf("Case #%d: %.7lf\n",l,jawab);
    }
    return 0;
}
