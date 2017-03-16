#include<cstdio>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
#include<cassert>
#include<ctime>
#include<cmath>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;
struct triple{
    int a,b,c;
    triple(int aa=0,int bb=0,int cc=0){
        a=aa,b=bb,c=cc;
    }
};
bool vis[500][202][202];
triple pred[500][202][202];
int D[500][202][202];
int mov[][2]={{0,1},{0,-1},{-1,0},{1,0}};
char dir[]={'N','S','W','E'};

void bfs(){

    queue<triple> Q;
    Q.push(triple(0,100,100));
    vis[0][100][100]=true;
    triple s;
    int it=0;
    while(!Q.empty()){
        s=Q.front();Q.pop();
        for(int i=0;i<4;i++){
            triple t=triple(s.a+1,s.b+mov[i][0]*(s.a+1),s.c+mov[i][1]*(s.a+1));
            if(s.a+1 >= 499) puts("yeah");
            if(t.b>200 || t.c>200 || t.b<0 || t.c<0) continue;
            if(vis[s.a+1][t.b][t.c]) continue;
            vis[t.a][t.b][t.c]=true;
            pred[t.a][t.b][t.c]=s;
            D[t.a][t.b][t.c]=i;
            Q.push(t);
        }
    }
    //printf("--> %d %d %d\n",s.a,s.b,s.c);
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,x,y;
    bfs();
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) if(!vis[i][j]) printf("vis %d %d\n",i,j);
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d%d",&x,&y);
        x+=100,y+=100;
        printf("Case #%d: ",I);
        string ans;
        for(int i=1;i<500;i++){
            if(vis[i][x][y]){
                triple t=triple(i,x,y);
                //printf("i=%d\n",i);
                while(!(t.a==0 && t.b==100 && t.c==100)){
                    //printf("%d %d %d\n",t.a,t.b,t.c);
                    ans+=dir[D[t.a][t.b][t.c]];
                    t=pred[t.a][t.b][t.c];
                }
                reverse(ans.begin(),ans.end());
                break;
            }
        }
        printf("%s\n",ans.c_str());
    }
    return 0;
}

