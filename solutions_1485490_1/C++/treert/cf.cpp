#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>

typedef long long ll;
using namespace std;
const int N = 110;

ll a[N],b[N];
int at[N],bt[N];
ll aa[110][N],bb[110][N];
int n,m;
ll dp[N][N];
void init(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i = 1; i <= 100; i++)
        for(j = 0; j < n; j++)
            aa[i][j] = 0;
    for(i = 1; i <= 100; i++)
        for(j = 0; j < m; j++)
            bb[i][j] = 0;
    for(i = 0; i < n; i++){
        scanf("%I64d%d",&a[i],&at[i]);
        aa[at[i]][i] = a[i];
    }
    for(i = 0; i < m; i++){
        scanf("%I64d%d",&b[i],&bt[i]);
        bb[bt[i]][i] = b[i];
    }
    for(i = 1; i <= 100; i++)
        for(j = 1; j < n; j++)
            aa[i][j] += aa[i][j-1];
    for(i = 1; i <= 100; i++)
        for(j = 1; j < m; j++)
            bb[i][j] += bb[i][j-1];
    for(i = 0; i <= n; i++)
        for(j = 0; j <= m; j++)
            dp[i][j] = -1;
    for(i = 0; i <= n; i++)
        dp[i][m] = 0;
    for(i = 0; i <= m; i++)
        dp[n][i] = 0;
}

ll gaoA(int i,int j,int k){
    if(i == 0) return aa[k][j-1];
    else return aa[k][j-1] - aa[k][i-1];
}
ll gaoB(int i,int j,int k){
    if(i == 0) return bb[k][j-1];
    else return bb[k][j-1] - bb[k][i-1];
}
ll dpf(int x,int y){
    if(dp[x][y] != -1) return dp[x][y];
    int i,j;
    dp[x][y] = max(dpf(x+1,y),dpf(x,y+1));
    if(at[x] == bt[y]){
        for(i = x+1; i <= n; i++)
            for(j = y+1; j <= m; j++){
                dp[x][y] = max(dp[x][y],dpf(i,j) + min(gaoA(x,i,at[x]) , gaoB(y,j,at[x])));
            }
    }
    return dp[x][y];
}
int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);
//    freopen("C-small-attempt0.in","r",stdin);
//    freopen("C.out","w",stdout);
    freopen("C-large.in","r",stdin);
    freopen("CC.out","w",stdout);
    int t,cas;
    scanf("%d",&t);cas = 0;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        init();
        dpf(0,0);
//        for(int i = 0; i <= n; i++){
//            for(int j = 0; j <= m; j++)
//                printf("%I64d ",dp[i][j]);
//            printf("\n");
//        }
//        printf("%I64d\n",gaoA(0,n,2));
        printf("%I64d\n",dp[0][0]);
//        printf("%lld\n",1002034343024134ll);
    }
}
