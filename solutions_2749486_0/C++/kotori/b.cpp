#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#define mp(x,y) make_pair((x),(y))
using namespace std;

 typedef pair<int,int> pii;

const int MAXINT=214748364;

const int dx[6]={-1,0,1,0,0,0};
const int dy[6]={0,1,0,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};

struct p{
       int x,y;
};

int f[70][70][70];
int n,m,k,ans,t,x,a,b,c,T;
map<pii,int> g;
//queue<p> q;
p q[1000000];
int tr[1000000];
int acc[1000000];


void pri(int now){
     if (now!=1) pri(tr[now]);
     int x=q[tr[now]].x;
     int y=q[tr[now]].y;
     int xx=q[now].x;
     int yy=q[now].y;
     if (x<xx) cout<<"E";
     if (xx<x) cout<<"W";
     if (y<yy) cout<<"N";
     if (yy<y) cout<<"S";
}

int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> T;
    int tot=0;
    while (T--){
          cin >> n>>m;
          

          q[1].x=0;
          q[1].y=0;
          tr[1]=1;
          acc[1]=1;
          g.clear();
          g[mp(0,0)]=1;
          int k=0,k1=1;
          int ans=0;
          while (k<k1){
                k++;
                int x=q[k].x;
                int y=q[k].y;
                if (acc[k]==500) continue;
                for (int i=0;i<4;i++){
                    int tx=x+dx[i]*acc[k];
                    int ty=y+dy[i]*acc[k];
                    if (g[mp(tx,ty)]==0){
                       q[++k1].x=tx;
                       q[k1].y=ty;
                       tr[k1]=k;
                       acc[k1]=acc[k]+1;
                       g[mp(tx,ty)]=1;
                       if (tx==n && ty==m){
                          cout << "Case #"<<++tot<<": ";
                          pri(k1);                          
                          
                          ans=1;
                          break;   
                       }
                    }
                }
                if (ans) break;      
          }
          cout <<endl;
          
    }
    //system("pause");
    return 0;
}
