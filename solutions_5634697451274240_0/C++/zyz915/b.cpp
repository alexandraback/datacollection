#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[1000];

void run(int cas) {
    scanf("%s", s);
    int l = strlen(s), ans = 0;
    s[l] = '+';
    for (int i = l - 1; i >= 0; i--)
        if (s[i] != s[i+1]) ans++;
    printf("Case #%d: %d\n", cas, ans);
}

int main() {
    int cas, tt;
    scanf("%d", &tt);
    for (cas = 1; cas <= tt; cas++)
        run(cas);
    return 0;
}

