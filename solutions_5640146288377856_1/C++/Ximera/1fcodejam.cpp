#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int check(int l, int r, int c) {

}

int main() {
    inp("input.txt");
    out("output.txt");
    int t, i, tt;
    cin >> t;
    for(tt = 1; tt <= t; tt++) {
        int r, c, w;
            cin >> r >> c >> w;
        int ans = (c / w) * r;
        if(c % w != 0)
            ans ++;
    //        cout << r << ' ' << c << ' ' << w << "\n";
    //        cout << ans << "\n";
        cout << "Case #" << tt << ": " << ans + w - 1 << "\n";
    }
}

