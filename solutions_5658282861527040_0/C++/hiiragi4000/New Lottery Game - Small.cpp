#include<stdio.h>
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int a,b,k,ans=0;
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<a;i++)for(int j=0;j<b;j++)if((i&j)<k)ans++;
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
