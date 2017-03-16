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

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){

        long long A, B, K; scanf("%lld%lld%lld", &A, &B, &K);

        long long ans = 0;
        for (long long i=0;i<A;i++) {
            for (long long j=0;j<B;j++) {
                if ((i&j) < K) {
                    //printf("(%lld %lld)\n", i,j);
                    ans ++;
                }
            }
        }

        printf("Case #%d: %lld\n",ti,ans);
    }
    return 0;
}
