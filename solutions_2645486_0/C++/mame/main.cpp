#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<algorithm>

typedef long long ll;
using namespace std;

ll data[20000];
ll si[20000];
ll rest[20000];
ll E;
ll R;
ll N;

int comparator(const void* va, const void* vb)
{
    ll* a = (ll*)va;
    ll* b = (ll*)vb;
    int v = (int)(data[*b] - data[*a]);
    if( v == 0 ){
        return (int)(*a - *b);
    }
    return v;
}

ll solveImpl(ll i, ll tryUse, ll en, ll total){
    // i で tryUse のエネルギーを使った場合の見返りを求める
    // エネルギーが足りなかったらここで終了
    if( tryUse > en ){ return total; }
    if( i >= N ){ return total; }
    total += data[i] * tryUse;
    en -= tryUse;
    en += R;
    if( en > E ){ en = E; }
    ll ma = 0;
    for(int z = 0;z <= E;++z){
        ll a = solveImpl(i+1,z,en,total);
        if( a > ma ){ ma = a; }
    }
    return ma;
}

ll solve()
{
    ll ans = 0;
    for(int i = 0;i <= E;++i){
        ll a = solveImpl(0,i,E,0);
        if( a > ans ){ ans = a; }
    }
    return ans;
}

int main(void){

    int T;
    scanf("%d",&T);

    for(int round = 0;round < T;++round){
        scanf("%lld %lld %lld",&E,&R,&N);
        for(int i = 0;i < N;++i){
            scanf("%lld",&data[i]);
            si[i]=i;
            rest[i]=E;
        }
        printf("Case #%d: %lld\n",round+1,solve());
    }

    return 0;
}