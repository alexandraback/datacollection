#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define A first
#define B second
#define mp make_pair
#define pii pair<int,int>
const int maxn=111;
string f[maxn*3][maxn*3];
int ex,ey;
queue<pii> q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
string dz[4]={"E","W","N","S"};
void run(){
    while (q.size()) q.pop();
    q.push(mp(maxn,maxn));
    f[maxn][maxn]="";
    while (!q.empty()){
        pii sta=q.front(); q.pop();
        int x,y,len=f[sta.A][sta.B].length()+1;
        string z;
        for (int k=0; k<4; k++){
            x=sta.A+dx[k]*len;
            y=sta.B+dy[k]*len;
            z=f[sta.A][sta.B]+dz[k];
            //cout<<x<<' '<<y<<' '<<z<<endl;
            if (x<0||y<0||x>maxn*3||y>maxn*3) continue;
            //cout<<x<<' '<<y<<' '<<z<<endl;
            if (f[x][y]=="#"){
                f[x][y]=z;
                q.push(mp(x,y));
            }
            if (f[ex][ey]!="#") return ;
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T; scanf("%d",&T);
    for (int tt=1;tt<=T;tt++){
        scanf("%d%d",&ex,&ey);
        ex+=maxn; ey+=maxn;
        for (int i=0; i<3*maxn; i++)
        for (int j=0; j<3*maxn; j++)
        f[i][j]="#";
        run();
        printf("Case #%d: %s\n",tt,f[ex][ey].c_str());
    }
}
