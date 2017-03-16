#include <stdio.h>
int shift[2000010][8];
int flag[2000010];
int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("gcj_qua_3_large.txt", "w", stdout);
    int pow10[10];
    pow10[0] = 1;
    for (int i = 1; i < 8; i++)
        pow10[i] = pow10[i - 1] * 10;
    for (int i = 0; i <= 2000000; i++)
    {
        shift[i][0] = i;
        int n = i, bcnt = 0;
        if (i == 0) 
            bcnt = 1;
        while (n)
        {
            n /= 10;
            bcnt++;
        }
        for (int j = 0; j < bcnt - 1; j++)
            shift[i][j + 1] = shift[i][j] / pow10[bcnt - 1] + shift[i][j] % pow10[bcnt - 1] * 10;
        shift[i][0] = bcnt - 1;
    }
    int T;
    scanf("%d", &T);
    int tcnt = 0;
    while (T--)
    {
        int A, B;
        scanf("%d%d", &A, &B);
        for (int i = A; i <= B; i++)
            flag[i] = 0;
        int ans = 0;
        for (int i = A; i <= B; i++)
        {
            if (flag[i])
                continue;
            flag[i] = 1;
            int cnt = 1;
            for (int j = 1; j <= shift[i][0]; j++)
            {
                if (shift[i][j] >= A && shift[i][j] <= B && !flag[shift[i][j]])
                {
                    //printf("%d\n", shift[i][j]);
                    flag[shift[i][j]] = 1;
                    cnt++;
                }
            }
            ans += cnt * (cnt - 1) / 2;
        }
        printf("Case #%d: %d\n", ++tcnt, ans);
    }
    return 0;
}
