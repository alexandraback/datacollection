#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,x,r,c;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%d",&x,&r,&c);
        if (r>c) swap(r,c);
        bool flag=0;
        if (x<=6&&r*c%x==0)
        {
            if (x==1||x==2) flag=1;
            else if (x==3)
            {
                if (r>=2) flag=1;
            }
            else if (x==4)
            {
                if (r>=3) flag=1;
            }
            else if (x==5)
            {
                if (r>=4) flag=1;
                else if (r==3&&c>5) flag=1;
            }
            else
            {
                if (r>=4) flag=1;
            }
        }
        printf("Case #%d: %s\n",cas,flag?"GABRIEL":"RICHARD");
    }
    return 0;
}
