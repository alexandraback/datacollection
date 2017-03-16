#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    FOR(tc,1,T+1) {
        ll C, D, V; cin >> C >> D >> V;
        unordered_set<ll> coins;
        FOR(i,1,D+1) {
            ll coin; cin >> coin;
            coins.insert(coin);
        }
        ll res  =LLONG_MAX;
        FOR(nadd, 0, 15) {
            if(res < LLONG_MAX) break;
            vector<bool> mask(nadd,true);
            mask.resize(V+1);
            reverse(begin(mask),end(mask));
            do {
                vector<bool> possible(V+1);
                possible[0] = true;
                auto acoins = coins;
                FOR(j,1,V+1)
                    if(mask[j]) acoins.insert(j);
                for(auto coin : acoins) FORD(v,0,V+1)
                    if(v - coin >= 0) 
                        possible[v] = possible[v] || possible[v-coin];
                if(all_of(begin(possible),end(possible),[](bool x){return x;}))
                    res = nadd;
                else {
                }
            } while(next_permutation(begin(mask),end(mask)));
        }
        cout << "Case #" << tc << ": " << res << endl;
    }
}
