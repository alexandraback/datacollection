#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

#define mp make_pair

vector< pair< long long, long long > > x, y;
map< pair< pair< int, int >, pair< long long, long long > >, long long > v;
int n, m;

long long f(int a, int b, long long c, long long d) {
    if ((a == n) || (b == m)) {
        return 0;
    }
    if (v.find(mp(mp(a, b), mp(c, d))) != v.end()) {
        return v[mp(mp(a, b), mp(c, d))];
    }
    long long ans = 0;
    long long la = x[a].first - c, lb = y[b].first - d;
    if (x[a].second == y[b].second) {
        if (la == lb) {
            ans = la + f(a + 1, b + 1, 0, 0);
        } else {
            if (la > lb) {
                ans = lb + f(a, b + 1, c + lb, 0);
            } else {
                ans = la + f(a + 1, b, 0, d + la);
            }
        }
    } else {
        ans = max(f(a + 1, b, 0, d), f(a, b + 1, c, 0));
    }
    return v[mp(mp(a, b), mp(c, d))] = ans;
}

int main() {
    int t;
    cin>>t;
    for (int tt = 0; tt < t; ++tt) {
        cin>>n>>m;
        v.clear();
        x.resize(n);
        y.resize(m);
        for (int i = 0; i < n; ++i) {
            cin>>x[i].first>>x[i].second;
        }
        for (int i = 0; i < m; ++i) {
            cin>>y[i].first>>y[i].second;
        }
        cout<<"Case #"<<(tt + 1)<<": "<<f(0, 0, 0, 0)<<endl;
    }
    return 0;
}

