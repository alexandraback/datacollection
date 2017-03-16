#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

long long e,R,n;
long long v[10005];
pair<long long, int> sv[10005];
bool vis[10005];

long long doit(long long l, long long r, long long le, long long re, long long seen) {
    //cerr << "  " << l << " " << r << " " << le << " " << re << endl;
    if (l >= r)return 0;
    if (l + 1 == r) {
        //cerr << l << " " << le << "->" << max(0LL, re - R) << endl;
        return (le - max(0LL, re - R)) * v[l];
    }
    while(vis[seen] == true || sv[seen].second < l || r <= sv[seen].second)seen++;
    long long ans = 0;
    long long maxi = sv[seen].second;
    vis[seen] = true;
    long long mine = max(0LL, re - R * (r - maxi));
    long long maxe = min(e, le + R * (maxi - l));
    //cerr << maxi << " " << maxe << "->" << mine << endl;
    ans += (maxe - mine) * v[maxi];
    ans += doit(l, maxi, le, maxe, seen + 1);
    ans += doit(maxi + 1, r, min(e, mine + R), re, seen + 1);
    return ans;
}

void solve() {
    cin >> e >> R >> n;
    rep(i,n) {
        cin >> v[i];
        sv[i] = make_pair(v[i], i);
    }
    
    rep(i,n)vis[i] = false;

    sort(sv, sv + n, greater<pair<long long, int> >());

    cout << doit(0, n, e, 0, 0) << endl;
}

int main() {
    int T;
    cin >> T;
    rep(i,T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
