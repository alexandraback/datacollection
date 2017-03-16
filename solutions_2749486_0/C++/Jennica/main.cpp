#include<cstring>
#include<cstdio>
char s[4][3] = {"WE", "EW", "SN", "NS"};

int main() {
    freopen("BBB.in","r",stdin);
    freopen("BBB.out","w",stdout);
    int x, y;
    int T, t, i;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        scanf("%d%d", &x, &y);
        printf("Case #%d: ",t);
        if (x > 0)
            for (i = 0; i < x; ++i)
                printf("%s", s[0]);
        else
            for (i = x; i < 0; ++i)
                printf("%s", s[1]);
        if (y > 0)
            for (i = 0; i < y; ++i)
                printf("%s", s[2]);
        else
            for (i = y; i < 0; ++i)
                printf("%s", s[3]);
        printf("\n");
    }
    return 0;
}