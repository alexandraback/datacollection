#include <stdio.h>

int t, tn;
int c, d;
long long v;
long long val[110];
long long sum;
int ans;

int main()
{
    freopen("C-large.in", "r", stdin);
    FILE *out = fopen("result.out", "w");
    int i;
    scanf("%d", &t);
    for (tn = 1; tn <= t; tn++)
    {
        scanf("%d %d %lld", &c, &d, &v);
        for (i = 1; i <= d; i++) scanf("%lld", &val[i]);
        
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
        
        printf("%d\n", tn);
        fprintf(out, "Case #%d: %d\n", tn, ans);
    }
}