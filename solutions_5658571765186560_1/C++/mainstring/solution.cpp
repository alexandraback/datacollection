#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("D-large.in","r", stdin);
    freopen("D-large.out","w", stdout);
    int t,cs=1,c,d,x;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&x,&c,&d);

        if(c<d) swap(c,d);
        printf("Case #%d: ",cs++);

        if((c*d)%x==0)
        {
            if(x==1)
            {
                printf("GABRIEL\n");
                continue;
            }
            else if(x==2)
            {
                printf("GABRIEL\n");
                continue;
            }
            if(x==3)
            {
                if(d>1)
                {
                    printf("GABRIEL\n");
                    continue;
                }
            }
            if(x==4)
            {
                if(d>2 || (c>4 && d>1))
                {
                    printf("GABRIEL\n");
                    continue;
                }
            }
            if(x==5)
            {
                if(d>2)
                {
                    printf("GABRIEL\n");
                    continue;
                }
            }
        }
        printf("RICHARD\n");
    }
}
