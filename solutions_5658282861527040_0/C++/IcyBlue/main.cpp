#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);

    int times;
    scanf("%d",&times);
    for (int t = 1; t<= times; t++)
    {
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        int cc = 0;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i & j) < k) cc++;
            }
        }
        printf("Case #%d: %d\n",t,cc);
    }
}
