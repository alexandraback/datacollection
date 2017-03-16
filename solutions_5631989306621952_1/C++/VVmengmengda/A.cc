#include<cstdio>
#include<cstring>
#define N 2000

char s[N], a[2*N];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T, i, j, ca = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int f, r;
        f = N, r = N+1;
        a[f--] = s[0];
        for (i = 1;s[i];i++) {
            if (s[i] >= a[f+1]) {
                a[f--] = s[i];
            }else {
                a[r++] = s[i];
            }
        }
        printf("Case #%d: ", ca++);
        for (i = f+1;i < r;i++) printf("%c", a[i]);
        puts("");
    }
}
