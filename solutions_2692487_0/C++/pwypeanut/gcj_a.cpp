#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tc;
vector<int> v;

int dp[1005][15], n;

int opt(int cur, int mote) {
    if ( mote == n ) return 0;
    int ans = 200000000;
    if ( cur > v[mote] ) ans = min(ans, opt(cur+v[mote], mote+1));
    else {
         ans = min(ans, opt(cur, mote+1)+1);
         if ( cur != 1 ) ans = min(ans, opt(cur+cur-1, mote)+1);
    }
    return ans;
}

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    scanf("%d", &tc);
    for ( int i = 0; i < tc; i++ ) {
        memset(dp, 0, sizeof(dp));
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
        
