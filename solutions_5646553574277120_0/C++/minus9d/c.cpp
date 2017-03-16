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

bool canmake(int v, vector<ll>& coins)
{
    int size = coins.size();
    REP(i,(1<<size)){
        int sum = 0;
        REP(j,size){
            if ((1<<j) & i) sum += coins[j];
        }
        if (sum == v) {
            // cout << "  sum = " << sum << endl;
            return true;
        }
    }
    return false;
}

ll solve(void)
{
    ll C,D,V;
    cin >> C >> D >> V;
    vector<ll> coins(D);
    REP(d,D){
        cin >> coins[d];
    }
    
    ll ans = 0;
    FOR(i,1,V+1) {
        if (!canmake(i,coins)){
            coins.pb(i);
            ++ans;
        }
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
