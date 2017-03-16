#include<iostream>
#include<stdio.h>
#include<climits>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,x,y;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",i);
        if(x>0)
        {
            for(int i=1;i<=x;i++)
            {
                printf("W");
                printf("E");
            }
        }
        else
        {
            for(int i=1;i<=x*(-1);i++)
            {
                printf("E");
                printf("W");
            }
        }
        if(y>0)
        {
            for(int i=1;i<=y;i++)
            {
                printf("S");
                printf("N");
            }
        }
        else
        {
            for(int i=1;i<=y*(-1);i++)
            {
                printf("N");
                printf("S");
            }
        }
        printf("\n");
    }
    return 0;
}
