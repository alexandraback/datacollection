// * (Knowing the mouse might one day find a way to heat up the spaghetti... It fills you with determination.)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
#include <bitset>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef unsigned long long ll;
const int BITS = 6;
const int J = 50;
const int N = 1000000;

ll toBase(ll x, ll base) {
    ll res = 0;
    ll cb = 1;
    while(x) {
        res += (x & 1) * cb;
        x >>= 1;
        cb *= base;
    }
    return res;
}

ll getDivisor(ll n){//x*x <= n
    for(ll x = 2; x<=1000; x++){
        if(n%x==0) return x;
    }
    return 0;
}

vector<ll> divs;

bool isCoin(ll n){
    divs.clear();
    rep(base,2,11){
        ll cd = getDivisor(toBase(n, base));
        if(cd) divs.push_back(cd);
        else return false;
    }
}

int main() {
    //freopen("smallout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cout << "Case #1:" << endl;
    int found = 0;
    rep(mask, 0, (1ll << (BITS - 2))) {
        ll x = (1ll << (BITS - 1)) + mask * 2 + 1;
        if(isCoin(x)){
            bitset<BITS> bs(x);
            cout << bs;
            for(auto x : divs) cout << " " << x;
            cout << endl;
            found++;
            if(found==J) break;
        }
    }
    return 0;
}
