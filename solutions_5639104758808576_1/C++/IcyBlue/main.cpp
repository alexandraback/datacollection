#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int times;
    freopen("A-large.in","r",stdin);
    freopen("A-large.txt","w",stdout);
    scanf("%d",&times);
    for (int t = 0; t <times; t++)
    {
        int smax;
        scanf("%d",&smax);
        int count = 0;
        int ans = 0;
        char tt;
        scanf("%c",&tt);
        for (int i = 0; i <= smax; i++)
        {
            int temp;
            scanf("%c",&tt);
            temp = tt - '0';
            if (count <= i) {
                    ans += i-count;
                    count = i;
            }
            count += temp;
        }
        printf("Case #%d: %d\n",t+1,ans);
    }
}
