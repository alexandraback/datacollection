#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

#define FOR(i,n,first) for(int i=first;i<n;i++)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define pb push_back
#define N 11000
#define M 121000
const int MOD=100000007;
const int INF = 0x3f3f3f3f;
const int MAX_N =130;
typedef pair<int,int> pii;
typedef long long int Int64;
//#define SMALL
//#define BIG

int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int strs[4]={'E','S','W','N'};
int vis[210][210];

struct POINT{
    int x,y;
    int step;
    int now;
    vector<char>vec;
}st,et;

bool ok(int a,int b){
    if(a<0||a>200||b<0||b>200)return false;
    if(vis[a][b])return false;
    return true;
}

void bfs(){
    memset(vis,0,sizeof vis);
    queue<POINT>que;
    st.x=st.y=100;st.step=0;
    st.now=1;
    vis[st.x][st.y]=1;
    que.push(st);
    st.vec.clear();
    while(!que.empty()){
        POINT top = que.front();
       // printf("%d,%d\n",top.x,top.y);
        /*for(int i=0;i<top.vec.size();i++){
                putchar(top.vec[i]);
        }
        putchar(10);*/
        que.pop();
        vis[top.x][top.y]=0;
        if(top.x==et.x&&top.y==et.y){
            //printf("top.step=%d\n",top.step);
            for(int i=0;i<top.vec.size();i++){
                putchar(top.vec[i]);

            }
            putchar(10);
           // printf("ok\n");
            return ;
        }
        for(int i=0;i<4;i++){
            POINT tt = top;
            tt.x += dir[i][0]*top.now;
            tt.y += dir[i][1]*top.now;
            if(ok(tt.x,tt.y)){
                vis[tt.x][tt.y]=1;
                tt.step = top.step+1;
                tt.now = top.now+1;
                tt.vec.clear();
                tt.vec = top.vec;

                tt.vec.pb(strs[i]);
                que.push(tt);
            }
        }
    }
}

int main()
{
    #ifdef SMALL
    freopen("B-small-attempt2.in","rt",stdin);
    freopen("text_sm.out","w",stdout);
    #endif
    #ifdef BIG
    freopen("text.in","rt",stdin);
    freopen("text_bg.out","w",stdout);
    #endif
    int cas;
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++){
        scanf("%d%d",&et.x,&et.y);
        et.x+=100,et.y+=100;
        printf("Case #%d: ",ii);
        bfs();

    }

    return 0;
}
