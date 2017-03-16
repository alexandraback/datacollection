#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <complex>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;
ll U, L;

bool isp(ll n) {
    vi v;
    while(n != 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    int length = v.size();
    int half = length / 2;
    rep(i,half) {
        if(v[i] != v[length-i-1]) return false;
    }
    return true;
}

bool solve(ll n) {
    ll sq = n * n;
    return (isp(n) && isp(sq));
}

int main() {
    cin >> T;
    repa(t,1,T) {
        cin >> L >> U;
        ll lower = (ll)ceil(sqrt(L));
        ll upper = (ll)floor(sqrt(U));
        ll cnt = 0;
        for(ll i=lower; i<=upper; i++) {
             if(solve(i)) {
                 // printf("%lld -> %lld\n", i, i*i);
                 cnt++;
            }
        }
        printf("Case #%d: %lld\n", t, cnt);
    }
}
