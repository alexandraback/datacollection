#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, r, c, w;
    cin >> t;
    for(int tt = 1; tt <= t; tt++)
    {
        cin >> r >> c >> w;
        int ans = c / w + w - 1;
        if(c / w * w != c)
            ans++;
        cout << "Case #" << tt << ": " << ans << "\n";
    }
    return 0;
}
