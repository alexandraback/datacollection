#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

long long res;

void solve(vector<pair<long long,long long> > A, vector<pair<long long, long long> > B, long long v) {
    vector<pair<long long,long long> > a=A;
    vector<pair<long long,long long> > b=B;
    long long m;

    if(a.empty() || b.empty()) return;

    // in
    while(!b.empty()) {
        if(a[0].second == b[0].second) {
            m = min(a[0].first, b[0].first);
            v += m;
            res = max(res, v);
            a[0].first -= m; if(a[0].first == 0) a.erase(a.begin());
            b[0].first -= m; if(b[0].first == 0) b.erase(b.begin());
            solve(a,b,v);
            v -= m;
            break;
        } else {
            b.erase(b.begin());
        }
    }

    a=A;
    b=B;

    // out
    a.erase(a.begin());
    solve(a,b,v);
    //m = min(a[0].first, b[0].first);
    //a[0].first -= m;
    //if(a[0].first == 0) a.erase(a.begin());
}

int main() {
    int T;

    cin >> T;
    for(int cs=1; cs<=T; cs++) {
        int N,M;

        cin >> N >> M;
        vector<pair<long long,long long> > a(N),b(M);
        for(int i=0;i<N;i++) {
            cin >> a[i].first >> a[i].second;
        }
        for(int i=0;i<M;i++) {
            cin >> b[i].first >> b[i].second;
        }

        res = 0;
        solve(a,b,0);
        printf("Case #%d: %lld\n", cs, res);
    }

    return 0;
}
