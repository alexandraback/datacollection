#include<queue>
#include<cstdio>
#include<algorithm>
#define mp make_pair
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int h,n,m,f[101][101],c[101][101];
int dp[101][101];
bool in[101][101];

queue< pair<int,int> > Q;

void update(int x,int y,int v){
    if(v<dp[x][y]){
        dp[x][y]=v;
        if(!in[x][y]){
            in[x][y]=1;
            Q.push(mp(x,y));
        }
    }
}

int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int _,cas=0;
    for(scanf("%d",&_);_--;){
        scanf("%d%d%d",&h,&n,&m);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                scanf("%d",c[i]+j);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                scanf("%d",f[i]+j);
        Q.push(mp(0,0));in[0][0]=1;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                dp[i][j]=(~0U>>1);
        dp[0][0]=0;
        while(!Q.empty()){
            pair<int,int> now=Q.front();Q.pop();
            in[now.first][now.second]=0;
            //printf("%d %d %d\n",now.first,now.second,dp[now.first][now.second]);
            
            for(int i=0;i<4;++i){
                pair<int,int> tmp=mp(now.first+dx[i],now.second+dy[i]);
                if(tmp.first<0||tmp.first>=n)continue;
                if(tmp.second<0||tmp.second>=m)continue;
                if(c[tmp.first][tmp.second]-f[now.first][now.second]<50)continue;
                if(c[tmp.first][tmp.second]-f[tmp.first][tmp.second]<50)continue;
                if(c[now.first][now.second]-f[tmp.first][tmp.second]<50)continue;
                int w=h-dp[now.first][now.second];
                int t=max(w-(c[tmp.first][tmp.second]-50),0);
                if(dp[now.first][now.second]==0&&t==0)update(tmp.first,tmp.second,0);
                else{
                    t+=dp[now.first][now.second];
                    if(h-t-f[now.first][now.second]>=20)update(tmp.first,tmp.second,t+10);
                    else update(tmp.first,tmp.second,t+100);
                }
            }
        }
        printf("Case #%d: %.8f\n",++cas,dp[n-1][m-1]/10.0);
    }
    return 0;
}
