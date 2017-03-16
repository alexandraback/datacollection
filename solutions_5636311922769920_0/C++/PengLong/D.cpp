#include <cstdio>

int main(int argc, char* argv[])
{
    int T, k, c, s;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test)
    {
        scanf("%d%d%d", &k, &c, &s);
        printf("Case #%d:", test);
        for (int i = 1; i <= s; ++i)
            printf(" %d", i);
        putchar('\n');
    }
    return 0;
}
