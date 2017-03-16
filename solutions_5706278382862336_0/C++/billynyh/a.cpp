#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

long long egcd(long long x, long long y, long long &m, long long &n) {
    int p = 0, q = 1, t;
    m = 1; n = 0;
    while (y) {
        t = x/y;
        m -= t*p; n -= t*q;
        p^=m^=p^=m; q^=n^=q^=n;
        y^=x^=y^=x %= y;
    }
    return x;
}


int main(){
    int tt; scanf("%d",&tt);



    for (int ti=1;ti<=tt;ti++){
        long long P, Q;
        char c;
        scanf("%lld%c%lld", &P, &c, &Q);

        long long t1,t2;
        long long x = egcd(P, Q, t1, t2);
        P /= x;
        Q /= x;

        //printf("%lld %lld\n", P, Q);

        t1 = Q;
        while (t1 > 1 && t1 % 2 == 0) t1 /= 2;
        if (t1 != 1) {
            printf("Case #%d: impossible\n",ti);
        } else {
            int ans = 0;
            t1 = Q;
            while (P < t1) {
                ans ++;
                t1 /= 2;
            }
            printf("Case #%d: %d\n",ti,ans);
        }
    }
    return 0;
}
