#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll reverseNum(ll x)
{
    ll res = 0;
    while(x){
        res *= 10;
        res += x%10;
        x /= 10;
    }
    return res;
}
//O(|V| + |E|) ~ O(3N)
ll sol(ll N)
{
    queue<ll> Q;
    ll inf = N + 1;
    vector<ll> dist(N + 1, inf);
    ll s = 1;
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        ll u = Q.front();
        if(u == N){
            return dist[u] + 1;
        }
        Q.pop();
        ll v = u + 1;
        if( (v <= N) && (dist[v] == inf) ){
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
        v = reverseNum(u);
        if( (v <= N) && (dist[v] == inf) ){
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
    return -1;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    //[1, 100]
    int T;
    //small [1, 1e6] large [1, 1e14]
    ll N;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        cin >> N;
        ll ans = sol(N);
        assert(ans != -1);
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}
