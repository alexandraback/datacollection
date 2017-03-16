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

int p[1100];


int main() {
    inp("input.txt");
    out("output.txt");
    int t, tt, i, j, n, ans, kol;
    scanf("%d", &t);
    for(tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        sort(p + 1, p + 1 + n);
        ans = p[n];
        for(i = 1; i <= 9; i++) {
            kol = i;
            for(j = 1; j <= n; j++)
                kol += max(0, (p[j] - 1) / i);
            ans = min(ans, kol);
        }
        printf("Case #%d: %d\n", tt, ans);
    }
}
