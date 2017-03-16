#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> TPL;

const int mr[]={-1,0,1,0};
const int mc[]={0,1,0,-1};

int h,n,m;
int at[102][102];
int dp[102][102];
int lo[102][102];
int hi[102][102];

int main(){
    int cs;
    scanf("%d",&cs);
    for(int no=1;no<=cs;no++){
        scanf("%d%d%d",&h,&n,&m);
        memset(at,0,sizeof(at));
        memset(dp,63,sizeof(dp));
        memset(lo,63,sizeof(lo));
        memset(hi,63,sizeof(hi));
        dp[1][1]=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            scanf("%d",&hi[i][j]);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            scanf("%d",&lo[i][j]);
        queue<PII> start;
        priority_queue<TPL> q;
        for(start.push({1,1});start.size();start.pop()){
            int sr,sc;
            tie(sr,sc)=start.front();
            q.push({0,start.front()});
            for(int o=0;o<4;o++){
                int tr=sr+mr[o];
                int tc=sc+mc[o];
                if(!dp[tr][tc]
                || hi[tr][tc]-lo[tr][tc]<50
                || hi[tr][tc]-lo[sr][sc]<50
                || hi[sr][sc]-lo[tr][tc]<50
                || hi[tr][tc]-h<50) continue;
                dp[tr][tc]=0;
                start.push({tr,tc});
            }
        }
        while(q.size()){
            int sr,sc;
            tie(sr,sc)=q.top().second;
            q.pop();
            if(at[sr][sc]) continue; else at[sr][sc]=1;
            for(int o=0;o<4;o++){
                int tr=sr+mr[o];
                int tc=sc+mc[o];
                if(hi[tr][tc]-lo[tr][tc]<50
                || hi[tr][tc]-lo[sr][sc]<50
                || hi[sr][sc]-lo[tr][tc]<50) continue;
                int v=max(0,h-dp[sr][sc]+50-hi[tr][tc]);
                if(h-dp[sr][sc]-v>=20+lo[sr][sc]) v+=10; else v+=100;
                if(dp[sr][sc]+v<dp[tr][tc]){
                    dp[tr][tc]=dp[sr][sc]+v;
                    q.push({-dp[tr][tc],PII(tr,tc)});
                }
            }
        }
        printf("Case #%d: %d.%d\n",no,dp[n][m]/10,dp[n][m]%10);
    }
}
