#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t, r, c, w;
    scanf("%d", &t);
    for(int h=1;h<=t;h++)
    {
        int wyn=0;
        scanf("%d%d%d", &r, &c, &w);
        while(c>2*w-1)
        {
            c-=w;
            wyn++;
        }
        if(c==w)
            wyn+=w;
        else
            wyn+=w+1;
        wyn*=r;
        printf("Case #%d: %d\n", h, wyn);
    }
    return 0;
}
