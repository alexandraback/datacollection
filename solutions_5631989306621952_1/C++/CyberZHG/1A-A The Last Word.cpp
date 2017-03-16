#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;

char s[MAXN];

int main() {
    int T;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s", s);
        int n = strlen(s);
        string f;
        f += s[0];
        for (int i = 1; i < n; ++i) {
            string l = s[i] + f;
            string r = f + s[i];
            f = l > r ? l : r;
        }
        printf("Case #%d: %s\n", t, f.c_str());
    }
    return 0;
}
