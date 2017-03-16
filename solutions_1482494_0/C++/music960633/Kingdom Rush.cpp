#include<stdio.h>
#include<algorithm>
int com[1001],a[1001],b[1001],ans;
void dfs(int n,int star,int step){
    int i;
    if(star==2*n){
        if(step<ans) ans=step;
        return;
    }
    if(step>ans) return;
    for(i=0;i<n;i++){
        if(com[i]==1){
            if(b[i]<=star){
                com[i]=2;
                dfs(n,star+1,step+1);
                com[i]=1;
                break;
            }
        }
        else if(com[i]==0){
            if(b[i]<=star){
                com[i]=2;
                dfs(n,star+2,step+1);
                com[i]=0;
                break;
            }
            else if(a[i]<=star){
                com[i]=1;
                dfs(n,star+1,step+1);
                com[i]=0;
            }
        }
    }
}
main(){
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);
    //freopen("tmp.txt","r",stdin);
    //freopen("tmp.out","w",stdout);
    int T,n,i,c;
    scanf("%d",&T);
    for(c=1;c<=T;c++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            com[i]=0;
        }
        ans=1000000;
        dfs(n,0,0);
        printf("Case #%d: ",c);
        if(ans!=1000000) printf("%d\n",ans);
        else printf("Too Bad\n");
    }
}
