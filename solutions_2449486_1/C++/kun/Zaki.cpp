#include<cstdio>
int T,a[101][101],n,m,u;
int main(){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int r=1;r<=T;r++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                u = 0;
                for(int k=0;u==0 && k<m;k++){
                    if(a[i][k] > a[i][j])
                        u = 1;
                }
                if(u == 1){
                    for(int k=0;u == 1 && k<n;k++){
                        if(a[k][j] > a[i][j])
                            u = 2;
                    }
                }
                if(u == 2){
                    printf("Case #%d: NO\n",r);
                    goto ou;
                }
            }
       printf("Case #%d: YES\n",r);
       ou:;   
    }
    return 0;
}
