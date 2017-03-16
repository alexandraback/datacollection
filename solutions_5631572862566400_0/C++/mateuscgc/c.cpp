#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        int bff[n+1];
        for(int j = 1; j <= n; j++) {
            cin >> bff[j];
            // cout << j << " - " << bff[j] << endl;
        }
        int best[n+1][2];
        memset(best, 0, sizeof(best));
        for(int j = 1; j <= n; j++) {
            int vis[n+1];
            memset(vis, 0, sizeof(vis));
            int next = j;
            int count = 0;
            while(!vis[bff[next]]) {
                vis[next] = 1;
                if(count > best[next][0])
                    best[next][0] = count;
                count++;
                next = bff[next];
            }
            if((bff[bff[next]] == next || bff[next] == j) && count > best[next][1]) {
                // cout << count << endl;
                best[next][1] = count+1;
            }
        }

        int ans = -1;
        int porra = 0;
        for(int j = 1; j <= n; j++) {
            int now = best[j][1];
            if(now == 2)
                porra++;
            if(bff[bff[j]] == j) {
                // cout << bff[bff[j]] << endl;
                now += best[j][0];
            }
            if(now > ans)
                ans = now;
        }
        if (porra == n)
            ans = n;
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}
