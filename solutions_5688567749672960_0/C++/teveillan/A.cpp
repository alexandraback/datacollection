#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i,l,r)  for(int i=(l); i<=(r); ++i)
#define REP(i,r)    for(int i=0; i<(r); ++i)
#define DWN(i,r,l)  for(int i=(r);i>=(l);--i)

#define pb push_back

typedef long long ll;
typedef pair<int, int>pii;

const int N = 1e7 + 100;

int dp[N];

string tostring(int x) {
    string str;
    if(x == 0)  return "0";
    while(x) {
        str.pb(x % 10 + '0');
        x /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int toint(string str) {
    int ret = 0;
    for(auto x: str) {
        ret = ret * 10 + x - '0';
    }
    return ret;
}

int main() {
    freopen("in.in", "r", stdin);
    freopen("out", "w", stdout);
    //
    //
    REP(i, N)   dp[i] = 1e9;
    dp[0] = 0;
    REP(i, 1e6 + 100) {
        if(i > 0)   dp[i] = min(dp[i], dp[i-1] + 1);
        string s = tostring(i);
        reverse(s.begin(), s.end());
        if(*s.begin() != '0')
        dp[i] = min(dp[i], dp[ toint(s) ] + 1);
        //cout << i << ' ' << dp[i] << endl;
    }


    int casnum = 0, casid = 0;
    ll n;
    cin >> casnum;
    while(casnum --) {
        cin >> n;
        printf("Case #%d: %d\n", ++casid, dp[n]);
    }
    return 0;
}

