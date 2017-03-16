#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <complex>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

ll solve(void)
{
    // cout << endl;

    ll C,D,V;
    cin >> C >> D >> V;

    //cout << "C,D,V = " << C << "," << D << "," << V << endl;

    vector<ll> coins(D);
    REP(d,D){
        cin >> coins[d];
    }
    sort(ALL(coins));

    // add 1
    ll ans = 0;
    if (coins[0] != 1) {
        ++ans;
        coins.pb(1);
    }
    sort(ALL(coins));

    // can make [1,possible_mx] 
    ll possible_mx = 1 * C;
    ll coin_sum = 1;
    int coin_idx = 1;
    while(1) {
        // cout << "possible_mx = " << possible_mx << endl;
                
        if (possible_mx >= V) break;

        if (coin_idx < coins.size()) {
            auto& coin = coins[coin_idx];
            // cout << "put coin: " << coin << endl;
            // add new coin
            if (coin > possible_mx + 1) {
                int new_coin = possible_mx + 1;
                coin_sum += new_coin;  // add coin
                ans += 1;
                // cout << new_coin << " is added." << endl;
            }
            // use coin
            else {
                coin_sum += coin;
                ++coin_idx;
            }
        }
        // no more coin
        else {
            int new_coin = possible_mx + 1;
            coin_sum += new_coin;
            ans += 1;
            // cout << new_coin << " is added." << endl;
        }

        possible_mx = coin_sum * C;
    }

    return ans;
}


int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        cout << "Case #" << (test+1) << ": " << solve() << endl;
    }

    return 0;
}
