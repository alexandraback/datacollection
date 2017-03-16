#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> II;

int n, m;
vector<II> toy, box;

ll calc(int a, int b, ll aa, ll bb){
    if(a == n || b == m) return 0;
    ll remaina = box[a].first - aa;
    ll remainb = toy[b].first - bb;
    if(box[a].second == toy[b].second && remaina > 0 && remainb > 0){
        ll used = min(remaina, remainb);
        return calc(a, b, aa + used, bb + used) + used;
    }
    if(remaina == 0) return calc(a + 1, b, 0, bb);
    if(remainb == 0) return calc(a, b + 1, aa, 0);
    return max(calc(a + 1, b, 0, bb), calc(a, b + 1, aa, 0));
}
    
ll newprob(){
    ll v, p;
    scanf("%d %d", &n, &m);
    box.clear();
    toy.clear();
    for(int i = 1; i <= n; ++i){
        scanf("%lld %lld", &v, &p);
        box.push_back(II(v, p));
    }
    for(int i = 1; i <= m; ++i){
        scanf("%lld %lld", &v, &p);
        toy.push_back(II(v, p));
    }
    calc(0, 0, 0, 0);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        printf("Case #%d: %lld\n", i, newprob());
    }
    return 0;
}
