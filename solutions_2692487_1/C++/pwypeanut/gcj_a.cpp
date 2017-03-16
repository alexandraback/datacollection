#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int tc, n;
vector<int> v;
map< pair<int, int>, int> m;

int opt(int cur, int mote) {
    if ( m.find(make_pair(cur, mote)) != m.end() ) return m[make_pair(cur, mote)];
    if ( mote == n ) return 0;
    int ans = 200000000;
    if ( cur > v[mote] ) ans = min(ans, opt(cur+v[mote], mote+1));
    else {
         ans = min(ans, opt(cur, mote+1)+1);
         if ( cur != 1 ) ans = min(ans, opt(cur+cur-1, mote)+1);
    }
    return m[make_pair(cur, mote)] = ans;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &tc);
    for ( int i = 0; i < tc; i++ ) {
        //memset(dp, -1, sizeof(dp));
        m.clear();
        v.clear();
        int start;
        scanf("%d%d", &start, &n);
        for ( int j = 0; j < n; j++ ) {
             int r;
             scanf("%d", &r);
             v.push_back(r);
        }
        sort(v.begin(), v.end());
        printf("Case #%d: %d\n", i+1, opt(start, 0));
    }
    return 0;
}
        
