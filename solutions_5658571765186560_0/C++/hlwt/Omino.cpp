#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("D-small-attempt3.in","r",stdin);
    freopen("D-small-attempt3.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d: ",++cas);
        if((r*c)%x) {
            printf("RICHARD\n");
            continue;
        }
        if(x==1) {
            printf("GABRIEL\n");
            continue;
        }
        if(x==2) {
            printf("GABRIEL\n");
            continue;
        }
        if(x==3) {
            if(min(r,c)==1)
                printf("RICHARD\n");
            else
                printf("GABRIEL\n");
            continue;
        }
        if(max(r,c)==4&&min(r,c)>=3)
            printf("GABRIEL\n");
        else
            printf("RICHARD\n");
    }
    return 0;
}
