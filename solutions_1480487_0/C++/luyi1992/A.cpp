#include<cstdio>

int T;
int s[300],sum,n;
double f[300],max,min,mid,st,left;

int main()
{
    scanf("%d",&T);
    for(int I = 1;I <= T;I++)
    {
        scanf("%d",&n);
        sum = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",s+i);
            sum += s[i];
        }
        for(int i = 0;i < n;i++) f[i] = double(s[i])/sum;
        printf("Case #%d:",I);
        for(int k = 0;k < n;k++)
        {
            max = 1;
            min = 0;
            while(max - min > 1e-9)
            {
                mid = (max + min) / 2;
                st = f[k] + mid;
                left = 1 - mid;
                for(int i = 0;i < n;i++) if (i != k)
                {
                    if (f[i] < st) left -= st - f[i];
                }
                if (left < 0) max = mid; else min = mid;
            }
            max *= 100;
            printf(" %lf",max);
        }
        puts("");
    }
    return 0;
}
