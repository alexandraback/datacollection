#include<stdio.h>
#include<string.h>
#define SIZE 111
int d[31][2],dp[SIZE][SIZE];
void fresh(int& x,int v){
    if(x<v)x=v;
}
int main(){
    int T,n,s,p,cs=0,i,j,k;
    for(i=0;i<=30;i++){
        if(i%3==0){
            d[i][0]=i/3;
            d[i][1]=i/3+1;
        }
        else if(i%3==1){
            d[i][0]=i/3+1;
            d[i][1]=i/3+1;
        }
        else{
            d[i][0]=i/3+1;
            d[i][1]=i/3+2;
        }
    }
    d[0][1]=-1;
    d[1][1]=-1;
    d[30][1]=-1;
    d[29][1]=-1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&s,&p);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            for(j=0;j<=n;j++){
                if(dp[i-1][j]>=0){
                    for(k=0;k<2;k++){
                        if(d[x][k]!=-1){
                            fresh(dp[i][j+k],dp[i-1][j]+(d[x][k]>=p));
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",++cs,dp[n][s]);
//        for(i=0;i<=n;i++,puts(""))
//            for(j=0;j<=n;j++)printf("%d ",dp[i][j]);
    }
    return 0;
}
