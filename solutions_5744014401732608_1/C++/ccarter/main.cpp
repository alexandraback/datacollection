#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int tt; cin >>tt;
    for (int tc=1;tc<=tt;tc++)
    {
        int b;
        long long m;
        cin >>b >>m;
        int c = (b*(b-1))/2;
        printf("Case #%d: ",tc);
        long long ma = 1ll << (b-2);
        int a[50]={0};
        for (int i=0;i<b;i++)
            a[i] = 1;
        a[b-1] = 0;
        if (ma < m)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            printf("POSSIBLE\n");
            long long gap = ma - m ;
            for (int i=0; i<b-2; i++)
            {
                if (gap & (1ll << (i)))
                    a[i+1] = 0;
            }
            for (int i=0;i<b;i++)
            {
                for (int j=0;j<b;j++)
                {
                    if (j==b-1)
                        printf("%d",a[i]);
                    else if (i<j)
                        printf("1");
                    else
                        printf("0");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
