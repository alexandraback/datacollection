#include <stdio.h>
using namespace std;
int t,x,r,c;
int main()
{
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    scanf("%d",&t);
    for(int k=1;k<=t;++k)
    {
        printf("Case #%d: ",k);
        scanf("%d %d %d",&x,&r,&c);
        if((r*c)%x!=0)printf("RICHARD\n");
        else if((r<=1||c<=1)&&x>=3)printf("RICHARD\n");
        else if((r==2||c==2)&&x==4)printf("RICHARD\n");
        else printf("GABRIEL\n");
    }
    return 0;
}
