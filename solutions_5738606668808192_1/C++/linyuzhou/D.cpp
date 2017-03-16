#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<stdio.h>
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
typedef long long LL;
LL pw[20][20];
LL Getnow(int t,int j){
    LL ret = 0;
    rep(i,0,15){
        if (t & (1<<i))
            ret += pw[j][i];
    }
    return ret;
}
LL power(LL x,int i,LL mod){
    LL ret = 1;
    while (i){
        if (i&1) ret = ret*x%mod;
        x = x*x%mod;
        i >>= 1;
    }
    return ret;
}
LL isPrime(LL t,int j){
    for (LL i = 2; i * i <= t; i++){
        if ((t%i+power(j,31,i))%i==0) return i;
    }
    return 0;
}
int main(){
    freopen("C-large.out","w",stdout);
    printf("Case #1:\n");
    int L = (1<<15) + 1, R = (1<<16) - 1;
    rep(i,2,10){
        pw[i][0] = 1;
        rep(j,1,16)
            pw[i][j] = pw[i][j-1]*i;
    }
    LL ans[15];
    int cnt = 0;
    rep(i,L,R){
        if (i%2==0) continue;
        bool ok = 1;
        rep(j,2,10){
            LL now = Getnow(i,j);
            ans[j] = isPrime(now,j);
            if (!ans[j]){
                ok = 0;
                break;
            }
        }
        if (ok){
            cnt++;
            printf("1000000000000000%I64d",Getnow(i,10));
            rep(j,2,10)
                printf(" %I64d",ans[j]);
            printf("\n");
        }
        if (cnt==500) break;
    }
    return 0;
}
