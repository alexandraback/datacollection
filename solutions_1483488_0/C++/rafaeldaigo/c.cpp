#include<stdio.h>
#include<string.h>

bool passed[2001000];

int main()
{
    int teste;
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int resp = 0;
        int n = 1;
        int temp = a / 10;
        int factor = 1;
        while (temp > 0)
        {
            n++;
            temp /= 10;
            factor *= 10;
        }
        for (int i = a; i <= b; i++)
        {
            passed[i] = false;
        }
        for (int i = a; i <= b; i++)
        {
            if (passed[i]) continue;
            int other = i / 10 + (i % 10) * factor;
            int count = 1;
            while (other != i)
            {
                if (other >= a && other <= b)
                {
                    passed[other] = true;
                    count++;
                }
                other = other / 10 + (other % 10) * factor;
            }
            resp += count * (count - 1) / 2;
        }
        printf("Case #%d: %d\n", t + 1, resp);
    }
    return 0;
}

