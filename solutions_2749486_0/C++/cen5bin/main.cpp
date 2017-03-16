#include <cstdio>
#include <cstring>
int main()
{
    freopen("a.in","r",stdin);
    freopen("b.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas<=T; cas++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",cas);
        if(x<0)
        for(int i=0; i<-x; i++)
        printf("EW");
        else
        for(int i=0; i<x; i++)
        printf("WE");
        if(y<0)
          for(int i=0; i<-y; i++)
        printf("NS");
        else
        for(int i=0; i<y; i++)
        printf("SN");
        puts("");
    }
    return 0;
}
