#include<stdio.h>
typedef long long lld;

int z[20], lz;
lld a[100];
int la = 0;
bool check(lld x){
    lz = 0;
    while(x > 0){
        z[lz++] = x % 10;
        x /= 10;
    }
    int k;
    for(k=0; k<lz/2; k++) if (z[k] != z[lz-k-1]) return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lld x, y;
    for(x = 1; x <= 10000000; x++){
        if (!check(x)) continue;
        y = x * x;
        if (check(y)){
            printf("%lld\n", y);
            a[la++] = y;
        }
    }
/*
    int cas, T;
    scanf("%d", &T);
    int k, cx, cy;
    for(cas=1; cas<=T; cas++){
        scanf("%lld %lld", &x, &y);
        for(cx=0; cx<la; cx++) if (a[cx]>=x) break;
        for(cy=0; cy<la; cy++) if (a[cy]>y) break;
        printf("Case #%d: %d\n", cas, cy-cx);
    }*/

    return 0;
}
