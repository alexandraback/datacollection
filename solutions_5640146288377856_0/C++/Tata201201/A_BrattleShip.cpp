#include<stdio.h>
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt = 1; tt <= t; tt++){
        int r,c,s,ans=0;
        scanf("%d%d%d",&r,&c,&s);
        ans = (c/s) * r + s - (c%s==0 ? 1 : 0);
        printf("Case #%d: %d\n",tt,ans);
    }
}
