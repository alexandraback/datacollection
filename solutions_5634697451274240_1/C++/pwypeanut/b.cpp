#include <bits/stdc++.h>
using namespace std;

int TC;

int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length() - 1; i++) if (s[i] != s[i + 1]) ans++;
        if (s[s.length() - 1] == '-') ans++;
        printf("Case #%d: %d\n", tc, ans);
    }
}
