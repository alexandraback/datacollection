#include <cstdio>



int main() {
    int T;
    int sm;
    char str[1010];
    int s[1010];
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%s", &sm, str);
        for (int i = 0; i <= sm; i++) {
            s[i] = str[i] - '0';
        }
        int cur = s[0];
        int ans = 0;
        for (int i = 1; i <= sm; i++) {
            if (s[i] == 0) continue;
            if (cur >= i) cur += s[i];
            else {
                ans += i - cur;
                cur = i + s[i];
            }
        }
        printf("Case #%d: %d\n", kase, ans);
    }
        
    return 0;
}
