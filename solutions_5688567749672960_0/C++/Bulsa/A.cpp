#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <ext/numeric>

#define pb push_back
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); --i)
#define all(c) begin(c),end(c)

using namespace std;
using namespace __gnu_cxx;
using ll = long long;

ll convert(ll in) {
    string x = to_string(in);
    reverse(all(x));
    return stoll(x);
}

ll size(ll in) {
    return to_string(in).size();
}

static ll dp[1000001];

int main() {
    ll tc;
    cin >> tc;
    FOR(i,1,1000001) {
        dp[i] = i;
    }
    FOR(i,1,1000001) {
        ll idx = convert(i);
        if(idx > 1000000) continue;
        dp[idx] = min(dp[idx],dp[i]+1);
        if(i > 1000000) continue;
        dp[i+1] = min(dp[i+1],dp[i]+1);
    }
    FOR(t,1,tc+1) {
        ll N; cin >> N;
        cout << "Case #" << t << ": " << dp[N] << endl;
    }
}
