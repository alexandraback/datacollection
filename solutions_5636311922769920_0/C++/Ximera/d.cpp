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

//lol p[200];


int main() {
    inp("input.txt");
    out("output.txt");
    int t, tt;
    scanf("%d", &t);
    for(tt = 1; tt <= t; tt++) {
        lol k, c, s, i, j, cur, pos;
        vector<lol> ans;
        printf("Case #%d: ", tt);
        scanf("%lld%lld%lld", &k, &c, &s);
        for(cur = i = 1; i <= s && cur <= k; i++) {
            pos = cur;
            for(j = 2; j <= c; j++) {
                pos = (pos - 1) * k + cur;
                if(cur != k) {
                    cur++;
                    pos++;
                }
//                cout << pos << "\n";
            }
            ans.pb(pos);
            cur++;
        }
        if(!ans.empty() && cur == k + 1) {
            for(auto x: ans)
                printf("%lld ", x);
            printf("\n");
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
