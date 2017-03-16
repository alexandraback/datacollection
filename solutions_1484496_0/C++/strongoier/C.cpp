#include <cstdio>

bool got;
int a[22], b[22], n;

void dfs(int dep, int x, int y)
{
    if (got)
        return;
    if (dep < n)
        for (int i = 0; i < 3; ++ i)
        {
            b[dep] = i;
            if (i == 1)
                dfs(dep + 1, x + a[dep], y);
            else if (i == 2)
                dfs(dep + 1, x, y + a[dep]);
            else
                dfs(dep + 1, x, y);
        }
    else if (x && y && x == y)
    {
        bool f = got = true;
        for (int i = 0; i < n; ++ i)
            if (b[i] == 1)
            {
                if (f)
                    f = false;
                else
                    putchar(' ');
                printf("%d", a[i]);
            }
        putchar('\n');
        f = true;
        for (int i = 0; i < n; ++ i)
            if (b[i] == 2)
            {
                if (f)
                    f = false;
                else
                    putchar(' ');
                printf("%d", a[i]);
            }
        putchar('\n');
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; ++ k)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i)
            scanf("%d", &a[i]);
        printf("Case #%d:\n", k);
        got = false;
        dfs(0, 0, 0);
    }
    return 0;
}
