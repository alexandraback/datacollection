#include<stdio.h>
#include<string.h>

char map[27] = "yhesocvxduiglbkrztnwjpfmaq";

int n;
int points[300];
int sum = 0;

bool safe(int index, double value)
{
    double remain = sum * (1 - value);
    double current = points[index] + sum * value;
    for (int i = 0; i < n; i++)
    {
        if (i == index) continue;
        if (current > points[i])
        {
            remain -= current - points[i];
            if (remain <= 0) return true;
        }
    }
    return false;
}

int main()
{
    int teste, t;
    int i, j;
    scanf("%d\n", &teste);
    for (t = 0; t < teste; t++)
    {
        scanf("%d", &n);
        sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &points[i]);
            sum += points[i];
        }
        printf("Case #%d:", t + 1);
        for (i = 0; i < n; i++)
        {
            double a = 0;
            double b = 1;
            double c;
            for (j = 0; j < 100; j++)
            {
                c = (a + b) / 2;
                if (safe(i, c))
                    b = c;
                else
                    a = c;
            }
            printf(" %lf", 100.0 * a);
        }
        printf("\n");
    }
    return 0;
}
