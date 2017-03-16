#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int x,n,m;
        scanf("%d%d%d",&x,&n,&m);
        int mi=min(n,m);
        if(n*m%x)
        {
            printf("RICHARD\n");
            continue;
        }
        if(x<3){
            printf("GABRIEL\n");
        }
        else if(x==3){
            if(mi==1)
            printf("RICHARD\n");
            else
            printf("GABRIEL\n");
        }
        else
        {
            if(mi<3)
            printf("RICHARD\n");
            else
            printf("GABRIEL\n");
        }
    }
    return 0;
}
