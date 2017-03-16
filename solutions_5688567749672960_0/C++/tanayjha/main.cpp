#include <bits/stdc++.h>
using namespace std;
long long ans[1000001];
int main()
{
    long long t, i, n, c, k, p, num, x, j, a[30];
    ans[1] = 1;
    for(i=2;i<=1000000;i++)
    {
            if(ans[i] == 0)
                ans[i] = ans[i-1] + 1;
            else
            {
                if(ans[i]>ans[i-1]+1)
                    ans[i] = ans[i-1]+1;
            }
            x = i;
            k = 0;
            while(x)
            {
                a[k++] = x%10;
                x /= 10;
            }
            num = 0;
            for(j = k-1;j >= 0; j--)
            {
                num += (a[j]*pow(10,(k-j-1)));
            }
            if(num>i && num < 1000001)
                ans[num] = ans[i]+1;

           // printf("%lld ", ans[i]);
    }
   // printf("\n");
    scanf("%lld", &t);
    for(i = 1; i<=t; i++)
    {
        c = 0;
        scanf("%lld", &n);
        printf("Case #%lld: %lld\n",i,ans[n]);
    }
    return 0;
}
