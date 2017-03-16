#include <stdio.h>

int t,r,c,w;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%d%d%d",&r,&c,&w);
        int nn=(c-1)/w+1;
        printf("Case #%d: %d\n",ca, r*nn+(w-1));
    }
    return 0;
}
