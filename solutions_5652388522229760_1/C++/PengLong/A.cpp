#include <cstdio>
#include <cstring>

bool mark[12] = {false};
int mksz;

inline void update(int n)
{
    while (n)
    {
        if (!mark[n % 10])
        {
            mark[n % 10] = true;
            ++mksz;
        }
        n /= 10;
    }
}

int main(int argc, char* argv[])
{
    int T, n, i;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test)
    {
        memset(mark, mksz = 0, sizeof(mark));
        scanf("%d", &n);
        for (i = 1; i <= 1000; ++i)
        {
            update(i * n);
            if (mksz == 10)
                break;
        }
        printf("Case #%d: ", test);
        if (i > 1000)
            puts("INSOMNIA");
        else
            printf("%d\n", i * n);
    }
    return 0;
}
