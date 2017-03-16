#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

int g[20][20];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool vis[20][20];
int n,m,k;

int bfs(){
    int temp=0;
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            vis[i][j]=0;
            if((i==0||j==0||i==n-1||j==m-1)&&g[i][j]==0){
                vis[i][j]=1;
                q.push(MP(i,j));
                temp++;
            }
        }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m||g[nx][ny]==1||vis[nx][ny])
                continue;
            q.push(MP(nx,ny));
            vis[nx][ny]=1;
            temp++;
        }
    }
    return n*m-temp;
}
int main() {
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        int d=n*m;
        int s=1<<d;
        int ans=k;
        for(int i=0;i<s;i++){
            int t=0;
            for(int j=0;j<d;j++){
                int w=(i>>j)&1;
                if(w) t++;
                g[j/m][j%m]=w;
            }
            if(t>=ans) continue;
            int tmp = bfs();
            if(tmp>=k) ans=t;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}

