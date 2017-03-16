#include <iostream>
#include <cstdio>
using namespace std;

int den[20], c, d, v;

bool flag[40];
void dfs(int i, int value)
{
    //printf("i = %d, value = %d\n", i, value);
    if (i == d)
    {
        if (value <= v) flag[value] = true;
        return;
    }
    dfs(i+1, value+den[i]);
    dfs(i+1, value);
}
bool check()
{
    for (int i = 1; i <= v; ++i)
        flag[i] = false;
    dfs(0, 0);
    for (int i = 1; i <= v; ++i)
        if (flag[i] == false) return false;
    return true;
}
int work()
{
    int res = 0;
    while (!check())
    {
        for (int i = 1; i <= v; ++i)
            if (flag[i] == false)
            {
                den[d++] = i;
                //printf("add %d\n", i);
                break;
            }
        ++res;
    }
    return res;
}
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d %d %d", &c, &d, &v);
        for (int i = 0; i < d; ++i)
            scanf("%d", &den[i]);
        printf("Case #%d: %d\n", cas, work());
    }
    return 0;
}
