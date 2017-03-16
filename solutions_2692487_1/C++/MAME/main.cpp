#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

typedef long long ll;
ll wn[1000];
ll n;
ll maxans;

ll solve(ll ans, ll depth, ll w)
{
    // だめな手
    if( ans >= maxans ){
        return ans;
    }
    // 終端
    if( depth >= n ){
        return ans;
    }
    // 食べられるなら食べる。
    // 食べられないなら、手数が n 未満ならドープ。
    // もしくは以降全部捨てる。
    if( wn[depth] < w ){
        return solve(ans,depth+1,w+wn[depth]);
    }

    // 以降全部捨てたとしたら？
    ll oa = ans;
    ans += n - depth;
    if( maxans > ans ){ maxans = ans; }

    // ここで補助したとしたら？
    ll sup = w-1;
    if( sup > 0 ){
        ll la = solve(oa + 1,depth,w+sup);
        if( la < ans ){ ans = la; }
    }

    return ans;
}

int main(void){

    int T;
    scanf("%d",&T);

    for(int round = 0;round < T;++round){
        ll ans = 0;
        ll w = 0;
        scanf("%lld %lld",&w,&n);
        for(ll i = 0;i < n;++i){
            scanf("%lld",&wn[i]);
        }
        // ソートして、小さいものをどんどん食べる。
        // 食べられなくなった場合、 w-1 を k 回足して超えるのが得か、
        // 全部捨てるのが得かを計算して覚えておく。
        std::sort(wn,wn+n);
        maxans = n;
        printf("Case #%d: %lld\n",round+1,solve(0,0,w));
    }

    return 0;
}