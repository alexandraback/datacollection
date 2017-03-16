#include <stdio.h>

int main()
{
    int n;
    int a;
    int t;
    int num[101];
    int i, j;

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &t);
    for(int k = 1 ; k <= t ; k++)
    {
        scanf("%d%d", &a, &n);
        for(i = 0 ; i < n ; i++)
            scanf("%d", &num[i]);

        for(i = 0 ; i < n ; i++)
            for(j = i + 1 ; j < n ; j++)
            {
                if(num[i] > num[j])
                {
                    int x = num[j];
                    num[j] = num[i];
                    num[i] = x;
                }
            }

        int op = 200;
        int sum_op = 0;
        int sum = a;
        bool breaker = false;
        for(i = 0 ; i < n ; i++)
        {
            //printf("%d %d (sum_op : %d, op : %d)\n", sum, num[i], sum_op, op);
            if(sum <= num[i])
            {
                if(sum_op + (n - i) < op)
                {
                    op = sum_op + n - i;
                }

                if(sum - 1 == 0)
                {
                    breaker = true;
                    break;
                }
                while(sum <= num[i])
                {
                    sum = sum * 2 - 1;
                    sum_op++;
                }

            }
            sum += num[i];
        }
        if(sum_op < op && !breaker)
            op = sum_op;

        printf("Case #%d: %d\n", k, op);
    }
}
