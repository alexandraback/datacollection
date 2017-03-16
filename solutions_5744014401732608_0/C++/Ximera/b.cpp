#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int c[55][55];
lol w[55];

int main() {
inp("input.txt");
out("output.txt");
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++) {
        int b;
        lol m;
        scanf("%d%lld", &b, &m);
        memset(c, 0, sizeof(c));
        memset(w, 0, sizeof(w));
        w[b] = 1;
        for(int i = b - 1; i >= 1; i--) {
            for(int j = i + 1; j <= b; j++) {
                if(w[i] + w[j] <= m) {
                    w[i] += w[j];
                    c[i][j] = 1;
                }
            }
        }
        printf("Case #%d: ", tt);
        if(w[1] == m) {
            printf("POSSIBLE\n");
            for(int i = 1; i <= b; i++, printf("\n"))
                for(int j = 1; j <= b; j++)
                    printf("%c", c[i][j] + 48);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
}
