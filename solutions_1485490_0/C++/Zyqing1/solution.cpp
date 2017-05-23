#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
const int maxn=110;
struct Node{
    LL num;
    int type;
}a[maxn],b[maxn];
int n,m;
LL dp[maxn][maxn][5];
void Dp()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][0][2]=a[i].num;
    for(int i=1;i<=m;i++)
        dp[0][i][4]=b[i].num;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i].type==b[j].type){
                dp[i][j][0]=dp[i-1][j-1][0]+min(a[i].num,b[j].num);
                dp[i][j][0]=max(dp[i][j][0],max(dp[i][j-1][0],dp[i-1][j][0]));
                dp[i][j][1]=dp[i][j-1][1]+min(dp[i][j-1][2],b[j].num);
                dp[i][j][2]=dp[i][j-1][2]-min(dp[i][j-1][2],b[j].num);
                dp[i][j][3]=dp[i-1][j][3]+min(dp[i-1][j][4],a[i].num);
                dp[i][j][2]=dp[i-1][j][4]-min(dp[i-1][j][4],a[i].num);
                dp[i][j][0]=max(dp[i][j][0],max(dp[i][j][1],dp[i][j][3]));
            }
            else{
                dp[i][j][0]=max(dp[i-1][j-1][0],max(dp[i][j-1][0],dp[i-1][j][0]));
                dp[i][j][1]=dp[i][j-1][1];
                dp[i][j][2]=dp[i][j-1][2];
                dp[i][j][3]=dp[i-1][j][3];
                dp[i][j][4]=dp[i-1][j][4];
                dp[i][j][0]=max(dp[i][j][0],max(dp[i][j][1],dp[i][j][3]));
            }
            //for(int k=0;k<5;k++)
                //cout<<i<<j<<k<<dp[i][j][k]<<endl;
           // cout<<endl;
        }
    }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i].num>>a[i].type;
        for(int i=1;i<=m;i++)
            cin>>b[i].num>>b[i].type;
        Dp();
        printf("Case #%d: ",cas);
        cout<<dp[n][m][0]<<endl;
    }
    return 0;
}
