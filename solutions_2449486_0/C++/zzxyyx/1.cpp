#include<stdio.h>
int g[110][110];
int hang(int u,int m,int x){
    for(int i=0;i<m;i++)
        if(g[u][i]>x)return 0;
    return 1;
}
int lie(int u,int n,int x){
    for(int i=0;i<n;i++)
        if(g[i][u]>x)return 0;
    return 1;
}
int solve(int n,int m){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&g[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(!hang(i,m,g[i][j])&&!lie(j,n,g[i][j]))
                return 0;
    return 1;
}
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m,cs,csi;
    scanf("%d",&cs);
    for(csi=1;csi<=cs;csi++){
        printf("Case #%d: ",csi);
        scanf("%d%d",&n,&m);
        puts(solve(n,m)?"YES":"NO");
    }
    return 0;
}
