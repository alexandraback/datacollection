#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
bool G[302][302][501];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string dirs="EWNS";

struct node{
    int x,y,c;
    string path;
    node(int _x, int _y, int _c, string cad){
        x=_x;y=_y;c=_c;
        path=cad;
    }
};
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      freopen("output","w",stdout);
   #endif
   int T,X,Y;
   cin>>T;
   REP(t,T){
        cin>>X>>Y;
        X+=120;
        Y+=120;
        queue<node>Q;
        memset(G,0,sizeof G);
        G[120][120][0]=1;
        Q.push(node(120,120,0,""));
        string ans;
        int maxi=0;
        while(!Q.empty()){
            node cur=Q.front();  Q.pop();    
            maxi=max(maxi,cur.c);    
            if(cur.y==X && cur.x==Y){
                ans=cur.path;
                break;
            }
            REP(i,4){
                int xx=(dx[i]*(cur.c+1))+cur.x;
                int yy=(dy[i]*(cur.c+1))+cur.y;
                if(min(xx,yy)>=0 && max(xx,yy)<300 && cur.c<500 && G[xx][yy][cur.c+1]==0){
                    Q.push((node(xx,yy,cur.c+1,cur.path+dirs[i])));
                    G[xx][yy][cur.c+1]=1; 
                }
            }            
            
        }
        printf("Case #%d: %s\n",t+1,ans.c_str());
   }   
   return 0;      
}

