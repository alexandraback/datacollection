#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

typedef long long ll;

ll func(ll r, ll g)
{
    return g * (2*g + 2*r - 1);
}

ll solve(ll r, ll t)
{
    // g == 1 で通過できることは問題から保証されている。
    // 上界は t に取って、検査を始める。
    ll left = 1;
    ll right = t / r;
    if( right > 707106780LL*2 ){
        right = 707106781LL*2;
    }
    while(true)
    {
        ll g = (left + right) / 2;
        if( func(r,g) <= t ){
            // 描ける。増やす。
            if( right - left == 1 ){
                g = right;
            }else if( right == left ){
                break;
            }
            left = g;
        }else{
            // かけない。減らす。
            if( right == left ){
                --left;
                break;
            }else if( right - left == 1 ){
                g = left;
            }
            right = g;
        }
    }
    return left;
}

int main(void){

    int T;
    scanf("%d",&T);

    for(int round = 0;round < T;++round){
        // r から塗り始めて、 g 本のリングを書くのに必要な塗料は
        // T(g) = g(2g + 2r - 1) で表される。
        // 二分探索で T(g) <= t < T(g+1) になる g を探す
        ll r;
        ll t;
        scanf("%lld %lld",&r,&t);
        printf("Case #%d: %lld\n",round+1,solve(r,t));
    }

    return 0;
}