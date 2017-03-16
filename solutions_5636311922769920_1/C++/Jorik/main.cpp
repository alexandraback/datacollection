#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        printf("Case #%d: ", kras);
        long long k, c, s;
        scanf("%lld %lld %lld", &k, &c, &s);
        if(s<k)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(long long i=0; i<s; i++)
        {
            long long voor = i;
            long long now = i;
            for(int j=0; j<c-1; j++)
            {
                now = voor*k+i;
                voor = now;
            }
            if(i != 0)
            {
                printf(" ");
            }
            printf("%lld", now+1);
        }
        printf("\n");
    }
    return 0;
}
