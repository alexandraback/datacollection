#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
#include <bitset>

using namespace std;

#define ll long long

int T;
ll r, t;
ll S(ll n, ll r) {
    return 2 * r * n - 3 * n + 2 * n * (n + 1);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&T);
    for(int c = 1;c<=T;c++) {
        cin>>r>>t;
        ll l = 1, h = 1<<30;
        ll res = 0;
        while(l <= h) {
            ll m = (l + h)/2;
            if(S(m, r) > t) {
                h = m - 1;
            }
            else {
                l = m + 1;
                res = m;
            }
        }
        cout<<"Case #"<<c<<": "<<res<<endl;
    }
    return 0;
}
