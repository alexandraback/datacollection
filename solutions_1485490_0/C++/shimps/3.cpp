#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef long long ll;

int n, m;
ll na[128], ta[128];
ll nb[128], tb[128];

ll dp[128][128];
ll fun(int ca, int cb) {
    if(dp[ca][cb] != -1) return dp[ca][cb];
    if(ca >= n || cb >= m) return dp[ca][cb] = 0;
    if(ta[ca] != tb[cb]) return dp[ca][cb] = max(fun(ca+1, cb), fun(ca, cb+1));
    int T = ta[ca];
    ll ma = na[ca], mb = nb[cb];
    int i = ca+1, j = cb+1;
    dp[ca][cb] = min(ma, mb) + fun(i, j);
    int done = 0;
    while(ma != mb && !done) {
        done = 1;
        if(ma < mb) {
            while(i < n && ta[i] != T) i++;
            if(i < n) {
                ma += na[i];
                done = 0;
                i++;
            }
        } else {
            while(j < m && tb[j] != T) j++;
            if(j < m) {
                mb += nb[j];
                done = 0;
                j++;
            }
        }
        dp[ca][cb] = max(dp[ca][cb], min(ma, mb) + fun(i, j));
    }
    return dp[ca][cb];
}

void do_case(int cn) {
    cin >> n >> m;
    FOR(i,0,n) cin >> na[i] >> ta[i];
    FOR(i,0,m) cin >> nb[i] >> tb[i];
    memset(dp,-1,sizeof(ll)*128*128);
    cout << "Case #" << cn << ": " << fun(0,0) << endl;
}

int main() {
    int T;
    cin >> T;
    FOR(te,0,T) do_case(te+1);
    return 0;
}
