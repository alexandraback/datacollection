#include <cstdio>
#include <cstring>

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int tt;
    char str[110];
    scanf("%d", &tt);
    for (int t=0 ; t<tt ; t++) {
        int ans = 0;
        scanf("%s", str);
        int len = strlen(str);
        for(int i=1 ; i<len ; i++) {
            if (str[i] != str[i-1]) ans++;
        }
        if (str[len-1] == '-') ans++;

        printf("Case #%d: %d\n", t+1, ans);
    }
}
