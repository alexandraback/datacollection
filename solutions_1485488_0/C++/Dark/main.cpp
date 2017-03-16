#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
#include <set>
#include <cstring>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-9
#define INF 1e20
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
LL gcd(LL a,LL b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
 struct G{
        int x,y;
}t,p;
int main()
{
    int T;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    For(ca,T)
    {
        int h,n,m;
        int f[105][105],c[105][105];
        int in[105][105],dp[105][105];
        int wet[105][105];
        scanf("%d%d%d",&h,&n,&m);
        For(i,n)For(j,m)scanf("%d",&c[i][j]);
        For(i,n)For(j,m)scanf("%d",&f[i][j]);
        mst(in,-1);
        mst(dp,-1);
        mst(wet,-1);
        For(i,n)For(j,m){
            if(c[i][j]-f[i][j]<50) in[i][j]=-1;
            else{
                in[i][j]=h-(c[i][j]-50);
                if(in[i][j]<0)in[i][j]=0;
            }
            wet[i][j]=h-f[i][j]-20;
            if(wet[i][j]<0) wet[i][j]=0;
        }
        dp[0][0]=0;
        t.x=0,t.y=0;
        queue<struct G>q;
        queue<struct G>qq;
        q.push(t);
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            t=q.front();q.pop();
           // printf("%d , %d\n",t.x,t.y);
            For(i,4){
                p=t;
                p.x += dx[i];
                p.y += dy[i];
                if(p.x<0||p.x>=n) continue;
                if(p.y<0||p.y>=m) continue;
                if(in[p.x][p.y]==-1) continue;
                if(c[t.x][t.y]-f[p.x][p.y]<50) continue;
                if(c[p.x][p.y]-f[t.x][t.y]<50) continue;
                if(c[p.x][p.y]-h<50) continue;
                if(dp[p.x][p.y] == -1){
                    dp[p.x][p.y] = 0;
                    q.push(p);
                    qq.push(p);
                }
            }
        }
        t.x=0,t.y=0;
        qq.push(t);
        while(!qq.empty()){
            t=qq.front();qq.pop();
            For(i,4){
                p=t;
                p.x += dx[i];
                p.y += dy[i];
                if(p.x<0||p.x>=n) continue;
                if(p.y<0||p.y>=m) continue;
                if(in[p.x][p.y]==-1) continue;
                if(c[t.x][t.y]-f[p.x][p.y]<50) continue;
                if(c[p.x][p.y]-f[t.x][t.y]<50) continue;
                int tim = max(dp[t.x][t.y],in[p.x][p.y]);
                if(tim<=wet[t.x][t.y])
                    tim += 10;
                else
                    tim += 100;
                if(dp[p.x][p.y] == -1 || dp[p.x][p.y]>tim){
                    dp[p.x][p.y] = tim;
                    qq.push(p);
                }
            }
        }
        printf("Case #%d: %lf\n",ca+1,0.1*dp[n-1][m-1]);
        //printf("%d\n",wet[0][0]);
    }
}
