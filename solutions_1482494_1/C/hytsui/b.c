#include <stdio.h>

int foo()
{
    int stars=0, cnt=0;
    int aa[2001], ba[2001], check[2001];
    int i, n, flag1=-1, flag2=-1;

    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d %d", &(aa[i]), &(ba[i]));
        check[i] = 2;
    }
    for (i=0; i<n; i++)
    {
        if (check[i]==2 && stars>=ba[i])
        {
            stars += 2;
            check[i] = 0;
            cnt++;
            flag2 = i;
            i = -1;
            flag1 = -1;
            flag2 = -1;
        }
        else if (check[i]==1 && stars>=ba[i])
        {
            stars += 1;
            check[i] = 0;
            cnt++;
            flag2 = i;
            i = -1;
            flag1 = -1;
            flag2 = -1;
        }
        else if (check[i]==2 && stars>=aa[i])
        {
            if (flag1==-1)
                flag1 = i;
            else if (ba[i]>ba[flag1])
                flag1 = i;
        }

        if (i == n-1)
        {
            if (flag1<0 && flag2<0)
            {
                if (stars != 2*n)
                    return -1;
                return cnt;
            }
            if (flag1>=0)
            {
                stars += 1;
                check[flag1] = 1;
                cnt++;
            }
            i = -1;
            flag1 = -1;
            flag2 = -1;
        }
    }
}

int main()
{
    int i, t, tmp;
    scanf("%d", &t);
    for (i=0; i<t; i++)
    {
        tmp = foo();
        if (tmp == -1)
            printf("Case #%d: Too Bad\n", i+1);
        else
            printf("Case #%d: %d\n", i+1, tmp);
    }
}
