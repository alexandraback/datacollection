#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t ; cas ++) {
        int r,c,w;
        cin >> r >> c >> w;
        int ans = 0;
        if(c % w == 0) ans = c / w + w - 1;
        else ans = c / w + w;
        cout << "Case #" << cas << ": " << ans << endl;
    }
    
    return 0;
}
