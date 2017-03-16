#include <cstdio>
#include <algorithm>

using namespace std;

//const int NMAX = 1000000;
//int d[NMAX], b[NMAX];

typedef long long ll;

int digits(ll x){
    int ret = 0;
    while(x > 0){
        ++ret;
        x /= 10;
    }
    return ret;
}
ll power(int x, int y){
    ll ret = 1;
    while(y-- > 0){
        ret *= x;
    }
    return ret;
}

ll rev(ll x){
    ll ret = 0;
    while(x > 0){
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

ll ans(ll n){
    if(n < 10) return n;
    int d, dd;
    ll p10, tmp;

    d = digits(n - 1);
    dd = d - d / 2;
    p10 = power(10, dd);
    tmp = (n - 1) / p10;
    if(tmp > power(10, d / 2 - 1)){
        return ans(rev(tmp*p10+1))+(n-tmp*p10);
    }else{
        return ans(tmp*p10)+(n-tmp*p10);
    }
}
/*
int test(){
    for(int i = 0; i < 10; i ++){
        d[i] = i;
    }
    for(int i = 10; i < NMAX; i++){
        if(i%10!=0 && rev(i) < i){
            if(d[rev(i)] < d[i-1]){
                d[i] = d[rev(i)] + 1;
                b[i] = rev(i);
            }else{
                d[i] = d[i-1] + 1;
                b[i] = i - 1;
            }
        }else{
            d[i] = d[i-1] + 1;
            b[i] = i - 1;
        }
    }
    printf("start\n");
    for(int i = 1; i < NMAX;i++){
        if(ans(i) != d[i]){
            printf("%d %d %d\n",i,ans(i),d[i]);
        }
    }
    printf("start\n");
    for(int i = 1; i < NMAX; i++){
        if(i%10!=0 && d[i] > min(d[rev(i)], d[i-1]) + 1){
            printf("wow");
            d[i] = min(d[rev(i)], d[i-1]) + 1;
        }
    }
    for(int i = 0; i < NMAX; i++){
        if(b[i] != i - 1)
            printf("%d : %d, %d\n", i, d[i], b[i]);
    }
    return 0;
}
*/
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ++ti){
        ll n;
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", ti, ans(n));
    }
    return 0;
}
