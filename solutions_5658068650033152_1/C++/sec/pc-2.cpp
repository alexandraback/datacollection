#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX = 1000000;
vector <vector<vector<int> > > dp;
int N,M;
void build()
{

    dp.clear();
    dp.resize(N+3);
    for( int i = 0; i < N+3; i++ ){
        dp[i].resize(M+3);
        for( int j = 0; j < M+3; j++ ){
            dp[i][j].resize(N*M+3);
            for( int k = 0; k < N*M+3; k++ )
                dp[i][j][k] = MAX;
        }
    }
}
int op[5] = {-2,-1,0,1,2};

int main(){
  //  freopen("in.txt","r",stdin);
   // freopen("oo.txt","w",stdout);
    freopen("C-large.in","r",stdin);
   
    freopen("C-sm.out","w",stdout);


    int T;
    scanf(" %d",&T);
    for(int t=0,K;t<T;t++){
        scanf(" %d %d %d",&N,&M,&K);
        build();
        for(int i=1;i<=M;i++)
            dp[1][i][i] = i;
        int ans = K;
        for(int n=1;n<N;n++){
            for(int m=1;m<=M;m++){
                for(int k=1;k<=n*m;k++){
                    if(dp[n][m][k]!=MAX){
                        for(int i=0;i<5;i++){
                            int mm = m+op[i];
                            if(mm>0 && mm<=M){
                                int nn = n+1;
                                int kk = k+mm;
                                int tmp = dp[nn][mm][kk];
                                if(n==1){
                                    if(dp[n][m][k]+mm < dp[nn][mm][kk])
                                        dp[nn][mm][kk] = dp[n][m][k]+mm;
                                }else{
                                    int cut = max(m-2,0);
                                    if(dp[n][m][k]-cut+mm < dp[nn][mm][kk])
                                        dp[nn][mm][kk] = dp[n][m][k]-cut+mm;
                                }
                                if(kk>=K)
                                    ans = min(ans,dp[nn][mm][kk]);
                            }
                        }
                    }
                }
            }
        }
         printf("Case #%d: %d\n",t+1,ans);
    }

    return 0;
}
