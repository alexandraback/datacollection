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
LL ans[111];
int cnt;
LL pw(LL x,int i){
    LL ret = 1;
    while (i){
        if (i&1) ret = ret * x;
        x = x * x;
        i>>=1;
    }
    return ret;
}
int main(){
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small.out","w",stdout);
    int T;
    cin>>T;
    rep(t,1,T){
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d: ",t);
        cnt = 0;
        LL kpc = pw(k,c);
        if (s*c < k) printf("IMPOSSIBLE\n");
        else{
            LL now = 1,kp = 1;
            rep(i,0,k-1){
                now += kp * i;
                kp = kp * k;
                if (kp == kpc || i == k-1){
                    ans[++cnt] = now;
                    now = 1;
                    kp = 1;
                }
            }
            rep(i,1,cnt-1)
                printf("%I64d ",ans[i]);
            printf("%I64d\n",ans[cnt]);
        }
    }
    return 0;
}
