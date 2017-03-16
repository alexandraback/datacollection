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
//    inp("input.txt");
//    out("output.txt");
    int t, n, i, ans, kol, j;
    string s;
    for(cin >> t, j = 1; j <= t; j++) {
        cin >> n >> s;
        ans = kol = 0;

        for(i = 0; i <= n; i++) {
            if(kol < i) {
                ans += i - kol;
                kol = i;
            }
            kol += (s[i] - 48);
        }
        printf("case #%d: %d\n", j, ans);
    }
}
