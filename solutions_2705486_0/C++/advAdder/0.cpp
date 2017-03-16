#include <cstdio>
#include <cstring>

int main()
{
    char st[10000];
    int ans = 0;
    while (scanf("%s", st) != EOF) {
        if (ans < strlen(st))
            ans = strlen(st);
    }
    printf("%d\n", ans);
    return 0;
}
