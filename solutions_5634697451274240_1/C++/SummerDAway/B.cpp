#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

char ch[111];

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        scanf("%s", ch);
        int ans = 0;
        for (int i = 1; i < strlen(ch); ++i) {
            if (ch[i] != ch[i-1]) ans++;
        }
        if (ch[strlen(ch)-1] == '-') ans++;
        printf("Case #%d: %d\n", tc, ans);
    }
}