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

string tostring(ll n) {
    if(n == 0)  return "0";
    string ret;
    while(n) {
        ret.pb(n%10 + '0');
        n /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

ll toint(string s) {
    ll ret = 0;
    for(auto x: s) {
        ret = ret * 10 + x - '0';
    }
    return ret;
}

ll dfs(ll n) {
    if(n <= 10) return n;
    ll ret = 0;
    string s = tostring(n);

    ll len = (s.size() + 1) / 2;
    ll ten = 1;
    REP(i, len) ten *= 10;

    ll tmp = n % ten;

    if(tmp == 0)    return dfs(n - 1) + 1;
    else if(tmp == 1) {
        ll tmp1 = n;

        reverse(s.begin(), s.end());
        ll tmp2 = toint(s);

        if(tmp1 <= tmp2)    return dfs(n-1) + 1;
        else return dfs(tmp2) + 1;
    } else {
        return dfs(n - tmp + 1) + tmp - 1;
    }
}


int main() {
    freopen("AAAA", "r", stdin);
    freopen("out", "w", stdout);
    int casnum, casid = 0;
    cin >> casnum;
    while(casnum--) {
        ll n;
        cin >> n;
        printf("Case #%d: %lld\n", ++casid, dfs(n));
    }
    return 0;
}

