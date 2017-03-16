#include <stdio.h>
#include <string.h>

#define MAX 1000010

typedef long long LL;

char str[MAX];
int f[MAX];
int n, L;

bool isCons(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return false;
    return true;
}

LL getAns() {
    L = strlen(str);
    LL ans = 0;
    int cnt = 0, pre = -1;
    for (int i=0; i<L; ++i) {
        if (isCons(str[i])) ++ cnt;
        else cnt = 0;
        
        if (cnt >= n)
            pre = i-n+1;
        
        if (pre != -1)
            ans += pre + 1;
    }
    return ans;
}

int main() {
    freopen("A-large.bin", "r", stdin);
    freopen("out", "w", stdout);
    int t, cs = 0;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%s%d", str, &n);
        LL ans = getAns();
        ++ cs;
        printf("Case #%d: %lld\n", cs, ans);
    }
    return 0;
}
