#include <stdio.h>

int t, tn;
int c, d, v;
int val[110];
int sum;
int ans;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int i;
    scanf("%d", &t);
    for (tn = 1; tn <= t; tn++)
    {
        scanf("%d %d %d", &c, &d, &v);
        for (i = 1; i <= d; i++) scanf("%d", &val[i]);
        
        sum = 0;
        ans = 0;
        for (i = 1; i <= d; i++)
        {
            while (sum*c < val[i]-1)
            {
                sum += sum*c+1;
                ans++;
            }
            sum += val[i];
        }
        while (sum*c < v)
        {
            sum += sum*c+1;
            ans++;
        }
        
        printf("Case #%d: %d\n", tn, ans);
    }
}