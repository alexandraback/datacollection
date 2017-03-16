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

bool dp[110];
int a[10];
vector <int> ans;
int used[110], otv, v;

void check(int cur, int kol) {
    bool bb = 1;
    int i;
//    cout << cur << ' ' << kol << "\n\t";
//    for(i = 1; i <= v; i++)
//        cout << dp[i] << ' ';
//    cout << "\n";
    for(i = 1; i <= v; i++)
        if(dp[i] == 0) {
            bb = 0;
            if(cur < ans.size() && i < ans[cur])
                return;
        }
    if(bb == 1) {
        otv = min(otv, kol);
        return;
    }
    if(cur == ans.size() || kol >= otv)
        return;
    bool dp1[110];
    for(i = 0; i <= v; i++)
        dp1[i] = dp[i];
    for(i = v; i >= 1; i--) {
        if(i >= ans[cur] && dp[i - ans[cur]])
            dp[i] = 1;
    }
    check(cur + 1, kol + 1);
    for(i = 0; i <= v; i++)
        dp[i] = dp1[i];
    check(cur + 1, kol);
}

int main() {
    inp("input.txt");
    out("output.txt");
    int t, tt;
    cin >> t;
    for(tt = 1; tt <= t; tt++) {
        int c, d, i, j;
        cin >> c >> d >> v;
        memset(dp, 0, sizeof(dp));
        memset(used, 0, sizeof(used));
        ans.clear();
        dp[0] = 1;
        for(i = 1; i <= d; i++) {
            cin >> a[i];
            used[a[i]] = 1;
            for(j = v; j >= a[i]; j--)
                if(dp[j - a[i]])
                    dp[j] = 1;
        }
        for(i = 1; i <= v; i++) {
            if(dp[i] == 0)
                for(j = i - 1; j >= 0; j--)
                    if(dp[j] && !used[i - j]) {
                        ans.pb(i - j);
                        used[i - j] = 1;
                    }
        }
        sort(ans.begin(), ans.end());
//        for(auto x: ans)
//            cout << x << ' ';
//        cout << "\n\t";
        otv = 3000;
        check(0, 0);
        printf("Case #%d: %d\n", tt, otv);
    }
}
