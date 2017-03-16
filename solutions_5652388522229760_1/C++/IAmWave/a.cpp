// * assuming i exist, i may or may not have eaten the entire bucket of fried chicken
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
#include <unordered_set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

void solve(ll n) {
    unordered_set<short> has;
    for(ll i = 1; i < 100000; i++) {
        ll cur = i * n;
        while(cur) {
            has.insert(cur % 10);
            cur /= 10;
        }
        if(has.size() == 10) {
            cout << (i * n);
            return;
        }
    }
    cout << "INSOMNIA";
}

int main() {
    freopen("large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(i, 0, q) {
        cout << "Case #" << (i + 1) << ": ";
        ll n;
        cin >> n;
        solve(n);
        cout << endl;
    }
    return 0;
}
