#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    int t;
    scanf("%d",&t);

    for(int cc=0;cc<t;cc++)
    {
        int x,r,c;

        scanf("%d%d%d",&x,&r,&c);
        int rc =r*c;
        int ans=0;
        if(x<=2)
        {
            if(rc%x==0)
                ans=1;
        }
        if(x==3)
        {
            if(rc%x==0)
            {
                if(r>=2&&c>=2)
                    ans=1;
            }
        }
        if(x==4)
        {
            if(rc%x==0)
            {
                if(r>=3&&c>=3)
                    ans=1;
            }
        }
        if(x==5)
        {
            if(rc%x==0)
            {
                if(r>=4&&c>=4)
                    ans=1;
                if(r==3||c==3)
                {
                    if(rc>=30)
                        ans=1;
                }
            }
        }
        if(x==6)
        {
            if(rc%x==0)
            {
                if(r>=4&&c>=4)
                    ans=1;
            }
        }

    if(ans)
        printf("Case #%d: GABRIEL\n",cc+1);
    else
        printf("Case #%d: RICHARD\n",cc+1);
    }
    return 0;
}
