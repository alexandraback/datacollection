#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out1_small.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int test=1; test<=T; test++)
    {
        long long N;
        scanf("%lld", &N);

        long long mask = 0;

        for(int i=1; ; i++)
        {
            if(i>100000)
            {
                printf("Case #%d: INSOMNIA\n", test);
                break;
            }

            long long M = N*i;

            while(M)
            {
                mask = (mask|(1<<(M%10)));
                M /= 10;
            }

            if(mask==(1<<10)-1)
            {
                printf("Case #%d: %lld\n", test, N*i);
                break;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
