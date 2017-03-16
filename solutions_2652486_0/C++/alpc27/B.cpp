#include <stdio.h>
#include <string.h>
#include <math.h>

int a[10];
int T,R,N,M,K;

bool ok(int k)
{
    int i,j;
    for (i = 0;i < K;i++)
    {
        if (a[i] % k == 0)
            return 1;
    }
    return 0;
}

void cal()
{
    int i,j,k;
    for (i = 0;i < K;i++)
    {
        if (a[i] == 125)
        {
            printf("555\n");
            return;
        }
        if (a[i] == 100)
        {
            printf("554\n");
            return;
        }
        if (a[i] == 75)
        {
            printf("553\n");
            return;
        }
        if (a[i] == 50)
        {
            printf("552\n");
            return;
        }
        if (a[i] == 80)
        {
            printf("445\n");
            return;
        }
        if (a[i] == 64)
        {
            printf("444\n");
            return;
        }
        if (a[i] == 48)
        {
            printf("443\n");
            return;
        }
        if (a[i] == 32)
        {
            printf("442\n");
            return;
        }
        if (a[i] == 45)
        {
            printf("335\n");
            return;
        }
        if (a[i] == 36)
        {
            printf("334\n");
            return;
        }
        if (a[i] == 81)
        {
            printf("333\n");
            return;
        }
        if (a[i] == 54)
        {
            printf("332\n");
            return;
        }
        if (a[i] == 60)
        {
            printf("543\n");
            return;
        }
        if (a[i] == 40)
        {
            printf("542\n");
            return;
        }
        if (a[i] == 30)
        {
            printf("532\n");
            return;
        }
        if (a[i] == 24)
        {
            printf("432\n");
            return;
        }
    }
    if (ok(25))
    {
        for (i = 0;i < K;i++)
        {
            if (ok(3))
            {
                printf("553\n");
                return;
            } 
            if (ok(4))
            {
                printf("554\n");
                return;
            }
            if (ok(2))
            {
                printf("552\n");
                return;
            } 
            printf("555\n");
            return; 
        }
    }
    if (ok(16))
    {
        for (i = 0;i < K;i++)
        {
            if (ok(3))
            {
                printf("443\n");
                return;
            } 
            if (ok(5))
            {
                printf("445\n");
                return;
            }
            printf("224\n");
            return; 
        }
    }
    if (ok(9))
    {
        for (i = 0;i < K;i++)
        {
            if (ok(5))
            {
                printf("335\n");
                return;
            } 
            if (ok(4))
            {
                printf("334\n");
                return;
            }
            if (ok(2))
            {
                printf("332\n");
                return;
            } 
            printf("333\n");
            return; 
        }
    }
    printf("222\n");
}

int main()
{
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k;
    scanf("%d", &T);
    for (k = 1;k <= T;k++)
    {
        scanf("%d%d%d%d", &R, &N, &M, &K);
        printf("Case #1:\n");
        for (i = 0;i < R;i++)
        {
            for (j = 0;j < K;j++)
                scanf("%d", &a[j]);
            cal();
        }
    }
    return 0;
}
