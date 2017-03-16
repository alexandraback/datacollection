#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int p,q,x,r,c;
    scanf("%d",&q);
    for(p=0;p<q;p++)
    {
        scanf("%d %d %d",&x,&r,&c);
        printf("Case #%d: ",p+1);
        if(x==1)
        {
            printf("GABRIEL\n");
        }
        else if(x==2)
        {
            if((r%2==0)||(c%2==0))
            {
                printf("GABRIEL\n");
            }
            else
            {
                printf("RICHARD\n");
            }
        }
        else if(x==3)
        {
            if(((r%3==0)&&(c>=2))||((r>=2)&&(c%3==0)))
            {
                printf("GABRIEL\n");
            }
            else
            {
                printf("RICHARD\n");
            }
        }
        else
        {
            if(((r%4==0)&&(c>=3))||((r>=3)&&(c%4==0)))
            {
                printf("GABRIEL\n");
            }
            else
            {
                printf("RICHARD\n");
            }
        }
    }
    return 0;
}
