#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 5;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int t, r, c, w, res;
    cin >> t;
    for(int cas = 1; cas <= t; cas ++) {
        cin >> r >> c >> w;
        int res = c / w;
        res = res * r;
        if (c % w != 0){
            res += w;
        }
        else{
            res += w - 1;
        }
        cout << "Case #" << cas << ": " << res << endl;
    }
    return 0;
}
