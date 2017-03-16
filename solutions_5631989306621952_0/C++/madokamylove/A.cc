#include <bits/stdc++.h>
using namespace std;

char s[1010];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%s", s);
        string cur = "";
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            string s1 = cur + s[i];
            string s2 = "";
            s2 += s[i];
            s2 += cur;
            cur = max(s1, s2);
        }
        printf("Case #%d: %s\n", cas, cur.c_str());
        fprintf(stderr, "%s\n", cur.c_str());
    }
    return 0;
}