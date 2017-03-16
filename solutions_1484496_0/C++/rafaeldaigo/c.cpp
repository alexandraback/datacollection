#include<stdio.h>
#include<string.h>

int n;
int values[30];
int found[3000000];
int sum[3000000];

void printMask(int mask)
{
    bool started = false;
    for (int i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) != 0)
        {
            if (started == false)
                started = true;
            else
                printf(" ");
            printf("%d", values[i]);
        }
    }
    printf("\n");
}

int main()
{
    int teste, t;
    int i, j;
    scanf("%d\n", &teste);
    for (t = 0; t < teste; t++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &values[i]);
        }
        for (i = 0; i < 3000000; i++)
        {
            found[i] = -1;
        }
        printf("Case #%d:\n", t + 1);
        sum[0] = 0;
        bool fin = false;
        for (j = 0; j < n; j++)
        {
            for (i = 1 << j; i < (1 << (j + 1)); i++)
            {
                int currentSum = sum[i - (1 << j)] + values[j];
                sum[i] = currentSum;
                if (found[currentSum] != -1)
                {
                    printMask(found[currentSum]);
                    printMask(i);
                    fin = true;
                    break;
                }
                found[currentSum] = i;
            }
            if (fin)
                break;
        }
        if (!fin)
            printf("Impossible\n");
    }
    return 0;
}
