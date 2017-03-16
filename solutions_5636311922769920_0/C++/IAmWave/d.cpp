// * This, however, is a snow poff.
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
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

void solve() {
    ll k, c, s;
    cin >> k >> c >> s;
    if(s * c < k) {
        cout << "IMPOSSIBLE";
        return;
    }
    ll rot = 0;
    ll mx = 1;
    rep(i,0,c) mx *= k;
    bool kek = false;
    rep(i,0,s){
        ll cur = 0;
        rep(j,0,c){
            cur *= k;
            cur += rot;
            rot = (rot + 1);
            if(rot >= k) {
                kek = true;
                rot %= k;
            }
        }
        cout << (cur+1) << " ";
        if(kek) break;
    }
}

int main() {
    freopen("small2.in", "r", stdin);
    freopen("out2.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(i, 0, q) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
