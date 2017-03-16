#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int maze[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int x,R,C;
int dfs(int p,int q)
{
    int ans = 1;
    maze[p][q] = 1;
    for(int i=0;i<4;i++){
        int u = p+dx[i];
        int v = q+dy[i];
        if(u>=0&&u<R&&v>=0&&v<C&&maze[u][v]==0){
            ans+=dfs(u,v);
        }
    }
    return ans;
}
bool check(int u,int d,int l,int r,int p,int q){
    if( p-u<0 || p+d>=R || q-l<0 || q+r>=C)
        return false;
    memset(maze,0,sizeof(maze));
    for(int i=0;i<=u;i++){
        maze[p-i][q] = 1;
    }
    for(int i=0;i<=d;i++){
        maze[p+i][q] = 1;
    }
    for(int i=0;i<=l;i++){
        maze[p][q-i] = 1;
    }
    for(int i=0;i<=r;i++){
        maze[p][q+i] = 1;
    }
    
    for(int i = 0;i<R;i++){
        for(int j =0;j<R;j++){
            if(maze[i][j]) continue;
            int tmp = dfs(i,j);
            if(tmp%x!=0)
                return false;
        }
    }
    return true;
    
}
bool solve()
{
    if (x>=9) return true;
    if ((R*C)%x!=0) return true;
    if (x<=2) return false;
    if(R>C) swap(R,C);
    int p,q;
    for(int i = 0;i<=x-1;i++){
        p = i+1;
        q = x-1-i+1;
        if(p>q) swap(p,q);
        if(p>R||q>C){
            return true;
        }
    }
    // u,d,l,r
    //
    bool flag;
    for(int u = 0;u<=x-1;u++){
        for(int d=0;u+d<=x-1;d++){
            for(int l=0;u+d+l<=x-1;l++){
                int r = x-1-(u+d+l);
                flag = false;
                for(int i =0;i<R&&!flag;i++){
                    for(int j =0;j<C&&!flag;j++){
                        flag = check(u,d,l,r,i,j)||check(l,r,d,u,i,j)||
                        check(d,u,r,l,i,j)||check(r,l,u,d,i,j)
                        ||check(u,d,r,l,i,j)||check(r,l,d,u,i,j)
                        ||check(d,u,l,r,i,j)||check(l,r,u,d,i,j);
                    }
                }
                if(!flag) return true;
            }
        }
    }
    return false;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int _=1;_<=T;_++){
        scanf("%d%d%d",&x,&R,&C);
        printf("Case #%d: %s\n",_,solve()?"RICHARD":"GABRIEL");
    }
    return 0;
}