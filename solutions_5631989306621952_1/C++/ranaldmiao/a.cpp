#include <bits/stdc++.h>
using namespace std;
int n, TC;
char s[2005];
int main () {
    scanf("%d", &TC);
    for (int t = 1; t <= TC; ++t) {
        scanf("%s", s);
        string ans = "a";
        ans[0] = s[0];
        n = strlen(s);
        for (int i = 1; i < n; ++i) {
            if (s[i] >= ans[0]) ans = s[i] + ans;
            else ans += s[i];
        }
        printf("Case #%d: %s\n", t, ans.c_str());
    }
}