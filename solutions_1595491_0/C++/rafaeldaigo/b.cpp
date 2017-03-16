#include<stdio.h>
#include<string.h>

int main()
{
    int teste, n, s, p;
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d %d %d", &n, &s, &p);
        int normal = 0;
        int surprised = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            if (3 * p - 2 <= a)
                normal++;
            else if (3 * p - 4 <= a && p > 1)
                surprised++;
        }
        int resp = normal;
        if (surprised > s)
            resp += s;
        else
            resp += surprised;
        printf("Case #%d: %d\n", t + 1, resp);
    }
    return 0;
}

