#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair
#define MAXLL ((1LL<<63)-1)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll Sk(ll a, ll k) {
    ll res=a+2*k-2;
    if (MAXLL / res < k) return MAXLL;
    res *= k;
    return res;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T, NT;
    ll i, j;
    ll r, t;
    cin>>NT;
    ll res;
    for(T=1; T<=NT; ++T) {
        cin>>r>>t;
        res = 0;
        ll b, e;
        b = 0;
        e = (1LL<<40);
        ll a = 2*r+1;
        while(e-b>1) {
            ll m = (b+e)/2;
            if (Sk(a, m) <= t) b = m;
            else e = m;
        }
        cout<<"Case #"<<T<<": "<<b<<endl;
    }
    return 0;
}
