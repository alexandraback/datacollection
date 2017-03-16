#include<stdio.h>
int as,v[15],n,e,r;
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
void dfs(int k,int e0,int sum){
    if(k==n){as=max(as,sum);return ;}
    for(int i=0;i<=e0;i++)
        dfs(k+1,min(e,e0-i+r),sum+v[k]*i);
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int csi,cs;
    scanf("%d",&cs);
    for(csi=1;csi<=cs;csi++){
        printf("Case #%d: ",csi);
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        as=0;
        dfs(0,e,0);
        printf("%d\n",as);
    }
    return 0;

}
