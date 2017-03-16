#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    for(int T = 1; T <= t; T++) {
        int r, c, w;
        cin >> r >> c >> w;
        int ans = 0;
        ans += (r-1) * (c/w);
        while(c >= w*2) {
            c -= w;
            ans += 1;
        }
        if(c == w)
            ans += w;
        else
            ans += w + 1;
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}