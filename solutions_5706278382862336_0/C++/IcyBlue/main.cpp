#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    freopen("A-small.in","r",stdin);
    freopen("A-small.txt","w",stdout);

    int times;
    scanf("%d",&times);
    for (int t = 0; t < times; t++)
    {
        long long a;
        scanf("%lld",&a);
        long long b;
        char c;
        scanf("%c",&c);
        scanf("%lld",&b);
        int count = 0;
        int ans = 0;
        while (count <= 40 && a != 0)
        {
            count ++;
            a *= 2;
            if (a >= b && ans == 0) ans = count;
            a = a % b;
        }
        if (a != 0)
        {
            printf("Case #%d: impossible\n",t+1);
        }
        else
        {
            printf("Case #%d: %d\n", t+1,ans);
        }
    }
}
