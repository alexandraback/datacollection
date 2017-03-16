#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
long long gcd(long long a, long long b){
    while(a && b){
        if(a < b)
            b %= a;
        else a %= b;
    }
    return a+b;
}
void solve(){
    int n, i;
    long long p, q;
    int res = 0;
    scanf("%lld/%lld", &p, &q);
    long long g = gcd(p, q);
    p/=g, q/=g;
    int kp=0, kq = 0;
    for(long long msk = p; msk; msk >>= 1){
        kp++;
    }
    long long msk;
    for(msk = q; (msk & 1) == 0; msk >>= 1){
        kq++;
    }
    res = kq-kp+1;
    if(res <= 0 || msk != 1 || res > 40)
        printf("impossible\n");
    else
        printf("%d\n", res);
}
int main(void){
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
