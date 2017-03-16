#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<map>

using namespace std;
map<long long, int> m;

long long gcd(long long x, long long y){
    if(x < y) swap(x, y);
    if(x%y==0)return y;
    return gcd(y, x%y);
}

int find(long long x, long long y){
    int a=0, b;
    long long t = gcd(x, y), T;
    T = x;
    m[x] = 1;
    //x/=t; y/=t;
    //printf("%lld %lld %lld\n", t, x, y);
    //system("pause");
    while(x < y and a <= 40){
        x*=2;
        a++;
    }
    if(a > 40) return -1;
    if(x == y) return a;
    else {
        //printf("%lld %lld\n", x, y);
        if(m[x-y] == 1) return -1;
        b = find(x-y, y);
        if(b == -1 or b+a > 40)return -1;
    }
    return a;
}

int i, n, k;
long long N, M, K;

int main(){
    freopen("A-small-attempt0 (2).in", "r", stdin);
    freopen("A_out.txt", "w", stdout);
int a, b, c, d;
int R, T;
cin >> R;
T = R;
while(T--){
    scanf("%lld/%lld", &N, &M);
    K = gcd(N, M);
    N /= K;
    M /= K;
    //cout << K << N << M;
    printf("Case #%d: ", R-T);
    m.clear();
    k = find(N, M);
    if(k!=-1)
        printf("%d", k);
    else printf("impossible");
    printf("\n");
}

return 0;
}
