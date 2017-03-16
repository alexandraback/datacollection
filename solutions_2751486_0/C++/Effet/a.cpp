#include <stdio.h>
#include <string.h>

#define MAX 1000010

char str[MAX];
int n, L;

bool isCons(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return false;
    return true;
}

int getAns() {
    // printf("%d\n", n);
    L = strlen(str);
    int ans = 0;
    for (int i=0; i<L; ++i) {
        for (int j=i+n-1; j<L; ++j) {
            int cnt = 0;
            for (int k=i; k<=j; ++k) {
                if (isCons(str[k])) {
                    ++ cnt;
                    if (cnt >= n) {
                        ans ++;
                        break;
                    }
                }
                else
                    cnt = 0;
            }
        }
    }
    return ans;
}

int main() {
    freopen("out", "w", stdout);
    int t, cs = 0;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%s%d", str, &n);
        int ans = getAns();
        ++ cs;
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}
