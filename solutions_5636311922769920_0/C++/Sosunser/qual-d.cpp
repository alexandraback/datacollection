#include <bits/stdc++.h>
using namespace std;

long long t,k,c,s;

int main(){
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    scanf("%lld",&t);
    for(long long j = 1; j <= t; j++){
        scanf("%lld%lld%lld",&k,&c,&s);
        printf("Case #%lld: ", j);
        for(long long i = 1; i <= k; i++){
            long long n = k;
            long long pos = i;
            for(long long p = 1; p < c; p++){
                pos = i+(pos-1)*k;
                n = n*k;
            }
            printf("%lld ",pos);
        }
        printf("\n");
    }
}