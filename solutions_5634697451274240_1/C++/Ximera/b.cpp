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


int main() {
    inp("input.txt");
    out("output.txt");
    int t, tt;
    scanf("%d", &t);
    for(tt = 1; tt <= t; tt++) {
        int i, cur, ans = 0;
        string s;
        cin >> s;
        printf("Case #%d: ", tt);
        for(i = s.size() - 1; i >= 0; i--) {
            cur = (s[i] == '+' ? 0: 1);
            if(cur != ans % 2) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
