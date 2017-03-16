#include <cstdio>
#include <cstring>

inline bool check(char c)
{
    if (c == 'a')
        return false;
    if (c == 'e')
        return false;
    if (c == 'i')
        return false;
    if (c == 'o')
        return false;
    if (c == 'u')
        return false;
    return true;
}

inline void deal()
{
    char st[1000003];
    int n;
    scanf("%s%d", st, &n);
    int ans = 0;
    int mark = -1;
    int last = 0;
    for (int i = 0; i < strlen(st); ++i) {
        if (check(st[i])) {
            ++last;
            if (last >= n)
                mark = i-n+1;
        } else
            last = 0;
        ans += mark+1;
    }
    printf("%d\n", ans);
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; ++i) {
        printf("Case #%d: ", i);
        deal();
    }
    return 0;
}
