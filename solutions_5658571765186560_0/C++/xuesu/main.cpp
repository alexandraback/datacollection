#include <stdio.h>
using namespace std;
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++)
    {
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        if(r*c%x!=0)
            printf("Case #%d: RICHARD\n",ti);
        else if(x==1||x==2)
            printf("Case #%d: GABRIEL\n",ti);
        else if(x==3)
        {
            if(r==1||c==1)
                printf("Case #%d: RICHARD\n",ti);
            else
                printf("Case #%d: GABRIEL\n",ti);
        }
        else if(x==4)
        {
            if((r==3&&c==4)||(r==4&&c==3)||(r==4&&c==4))
                printf("Case #%d: GABRIEL\n",ti);
            else
                printf("Case #%d: RICHARD\n",ti);
        }
    }
    return 0;
}
