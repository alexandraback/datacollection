#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

long long t, k, c, s, x, w, pot[105];

int main() {
    long long i, j;
    scanf("%lld", &t);
    for (i=0; i<t; ++i) {
        scanf("%lld %lld %lld", &k, &c, &s);
        printf("Case #%lld:", i+1);
                //cout<<"    "<<pow(5, 0);
        if (k==s) {
            pot[0]=1;
            for (j=1; j<=c; ++j) {
                pot[j]=pot[j-1]*k;
            }
            x=0;
            for (j=0; j<c; ++j) {
                x=pot[j] + x;
            }
            w=1;
            if (k != 1) {
                for (j=0; j<k; ++j) {
                    printf(" %lld", w);
                    w+=x;
                }
            } else {
                printf(" 1");
            }
        } else {
            printf(" IMPOSSIBLE");
        }
        printf("\n");
    }
    return 0;
}
