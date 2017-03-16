#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

//~ typedef long long ll;
typedef int ll;

int cnt[1000006];
inline ll reverse(ll n){
    ll a = 0;
    while (n)
        a *= 10,
        a += n%10,
        n/= 10;
    return a;
}
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cnt[1] = 1;
    queue<ll> q;
    q.push(1);
    while (!q.empty()){
        ll t = q.front(); q.pop();
        if (t==1000000) break;
        if (!cnt[t+1]){
            cnt[t+1] = cnt[t]+1;
            q.push(t+1);
        }
        if (!cnt[reverse(t)]){
            cnt[reverse(t)] = cnt[t]+1;
            q.push(reverse(t));
        }
    }
    //~ for (int i = 0, t = 1; i < 4; t *= 10, ++i)
        //~ cout<<cnt[t]<<endl;
    //~ return 0;
    int _T;
    scanf("%d", &_T);
    for (int T = 1; T <= _T; T++){
        long long N, ans;
        scanf("%lld", &N);
        ans = cnt[N];
        printf("Case #%d: %lld\n", T, ans);
    }
    return 0;
}
