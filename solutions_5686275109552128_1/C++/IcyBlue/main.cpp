#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int pancakes[1000];
int main()
{

    int times;
    freopen("B-large.in","r",stdin);
    freopen("B-large.txt","w",stdout);
    scanf("%d",&times);
    for (int t = 0; t < times; t++)
    {
        int d;
        scanf("%d",&d);
        int max = 0;
        for (int i = 0; i < d; i++)
        {
            scanf("%d",&pancakes[i]);
            if (pancakes[i]>max)    max = pancakes[i];
        }
        int mintime = max;
        for (int i = 1; i <= max; i++)
        {
            int count = 0;
            for (int j = 0; j < d; j++)
            {
                count += pancakes[j]/i;
                if (pancakes[j] % i == 0) count --;
            }
            if (count + i < mintime) mintime = count +i;
        }
        printf("Case #%d: %d\n",t+1,mintime);
    }
}
