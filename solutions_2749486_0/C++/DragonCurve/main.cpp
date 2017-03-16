#include <stdio.h>

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("Case #%d: ",t);
        if(x>0)
        {
            for(;x!=0;x--)
                printf("WE");
        }
        else for(;x!=0;x++) printf("EW");
        if(y>0)
        {
            for(;y!=0;y--)
                printf("SN");
        }
        else for(;y!=0;y++) printf("NS");
        printf("\n");
    }
    return 0;
}
