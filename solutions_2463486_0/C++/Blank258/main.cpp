# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

__int64 ans[40];

int judge0(__int64 n)
{
    int i;
    bool escape;
    char s[20];
    sprintf(s, "%I64d", n);
    n = strlen(s);
    for(i = 0, escape = false; i <= n/2; i++)
    {
        if(s[i] != s[n-1-i])
        {
            escape = true;
            break;
        }
    }
    if(escape)
    {
        return 0;
    }
    return 1;
}

void judge()
{
    __int64 i, k = 0;
    memset(ans, false, sizeof(ans));
    for(i = 1; i <= 35; i++)
    {
        if(judge0(i))
        {
            if(judge0(i*i))
            {
                ans[k++] = i*i;
            }
        }
    }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out", "w", stdout);
    __int64 t, a, b, i, count, cnt = 1;
    judge();
    scanf("%I64d", &t);
    while(cnt <= t)
    {
        count = 0;
        scanf("%I64d %I64d", &a, &b);
        for(i = 0; ans[i] < a && ans[i] != 0; i++);
        for(; ans[i] <= b && ans[i] != 0; i++)  count++;
        printf("Case #%I64d: %I64d\n", cnt++, count);
    }
    return 0;
}

