#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,c;
int G[105][105];
char ZH[5];
void Do(){
    int i,j,k,l;
    ZH[0]='.';
    ZH[1]='*';
    ZH[2]='c';
    memset(G,0,sizeof(G));
    if(n*m-1==c){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)G[i][j]=1;
        G[1][1]=2;
    }else if(n==1){
        for(i=1;i<=c;i++)G[1][i]=1;
        for(i=c+1;i<=m;i++)G[1][i]=0;
        G[1][m]=2;
    }else if(m==1){
        for(i=1;i<=c;i++)G[i][1]=1;
        for(i=c+1;i<=n;i++)G[i][1]=0;
        G[n][1]=2;
    }else if(n==2){
        if(c&1){
            printf("Impossible\n");
            return ;
        }
        if(n*m-c<4){
            printf("Impossible\n");
            return ;
        
        }
        for(i=1;i<=c/2;i++)G[1][i]=G[2][i]=1;
        for(;i<=m;i++)G[1][i]=G[2][i]=0;
        G[1][m]=2;
    }else if(m==2){
        if(c&1){
            printf("Impossible\n");
            return ;
        }
        if(n*m-c<4){
            printf("Impossible\n");
            return ;
        
        }
        for(i=1;i<=c/2;i++)G[i][1]=G[i][2]=1;
        for(;i<=n;i++)G[i][1]=G[i][2]=0;
        G[n][1]=2;
    }else {
        if(n*m-c<4){
            printf("Impossible\n");
            return ;
        }
        if(n*m-c==4){
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)G[i][j]=1;
            G[1][1]=2;
            G[1][2]=G[2][1]=G[2][2]=0;
        }else{
            if(n*m-c<9&&(n*m-c)%2==1){
                printf("Impossible\n");
                return ;
            }
            if((n*m-c)%2==0){
                for(i=1;i<=n;i++)
                    for(j=1;j<=m;j++)G[i][j]=1;
                k=n*m-c;
                G[1][1]=2;
                G[1][2]=G[2][1]=G[2][2]=0;
                k-=4;
                for(i=3;i<=m&&k>0;i++){
                    k-=2;
                    G[1][i]=G[2][i]=0;
                }
                j=-1;
                while(k>0){
                    j+=2;
                    if(j+1>m)break;
                    for(i=3;i<=n&&k>0;i++){
                        k-=2;
                        G[i][j]=G[i][j+1]=0;
                    }
                }
                if(k>0){
                    for(i=3;i<=n&&k>0;i++){
                        k--;
                        G[i][m]=0;
                    }
                }
            }else{
                for(i=1;i<=n;i++)
                    for(j=1;j<=m;j++){
                        G[i][j]=1;
                    }
                for(i=1;i<=3;i++)
                    for(j=1;j<=3;j++){
                        G[i][j]=0;
                    }
                G[1][1]=2;
                k=n*m-c;
                k-=9;
                for(i=4;i<=m&&k>0;i++){
                    k-=2;
                    G[1][i]=G[2][i]=0;
                }
                for(i=4;i<=n&&k>0;i++){
                    k-=2;
                    G[i][1]=G[i][2]=0;
                }
                if(k>0){
                    k++;
                    G[3][3]=1;
                    j=1;
                    while(k>0){
                    if(k==1)break;
                    j+=2;
                    if(j+1>m)break;
                    for(i=3;i<=n&&k>1;i++){
                        k-=2;
                        G[i][j]=G[i][j+1]=0;
                    }
                }
                if(k==1){
                    if(i<=n){
                        k--;
                        G[i][j]=0;
                        G[i][j+1]=1;
                    }else{
                        j+=2;
                        k--;
                        G[3][j]=0;
                        G[3][j+1]=1;
                    }
                }else{
                    for(i=3;i<=n&&k>0;i++){
                        k--;
                        G[i][j]=0;
                     }
                }
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            putchar(ZH[G[i][j]]);
        }
        putchar('\n');
    }
}
int main(){
    int T,i,j,k,l,tt;
    freopen("C.out","w",stdout);
    tt=0;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d%d",&n,&m,&c);
       tt++;
       printf("Case #%d:\n",tt);
       Do();
    }
    return 0;
}
