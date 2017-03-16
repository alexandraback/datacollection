#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n,m;

int flag;
char mp[30][30];
int mm[30][30];
bool vis[30][30];
void getnum(int &x,int &y,int num){
    x=num/m;
    y=num%m;
}
int dx[8]={-1,-1,-1,0,0,1,1,1};

int dy[8]={-1,0,1,-1,1,-1,0,1};
int is_ok(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m)return 1;
    return 0;
}
int bfs(int s,int t,int num){
    int x,y,xx,yy;
    int ans=1;
    queue<pair<int,int> >q;
    q.push(make_pair(s,t));
    memset(vis,0,sizeof(vis));
    vis[s][t]=1;
    // printf("dslkksdj\n");
    while(!q.empty()){

        pair<int,int> pii=q.front();q.pop();
        x=pii.first,y=pii.second;
        if(mm[x][y]!=0)continue;
        for(int i=0;i<8;i++){
            xx=x+dx[i],yy=y+dy[i];
            if(is_ok(xx,yy)&&mm[xx][yy]>=0&&!vis[xx][yy]){
                ans++;
                vis[xx][yy]=1;
                q.push(make_pair(xx,yy));
            }
        }
    }
    if(ans==num)return 1;
    return 0;
}

int cal(){
    memset(mm,-1,sizeof(mm));
    int x,y;
    int zero=0;
    int num=0;
    int s,t;
    int ss,tt;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(mp[i][j]=='.'){
            mm[i][j]=0;
            ss=i,tt=j;
            num++;
            for(int k=0;k<8;k++){
                x=i+dx[k],y=j+dy[k];
                if(is_ok(x,y)&&mp[x][y]=='*'){
                    mm[i][j]++;
                }
            }
            if(mm[i][j]==0){
                s=i,t=j;
                zero++;
            }
        }
    }
    if(zero){
        if(bfs(s,t,num)){
                mp[s][t]='c';
                return 1;
        }
    }
    else if(num==1){
        mp[ss][tt]='c';
        return 1;
    }
    else return 0;
    return 0;
}
void dfs(int num,int mine ){
    //printf("%d %d\n",num,mine);
    if(num==n*m){
        if(cal()){
            flag=1;
        }
        return ;
    }
    int x,y;
    getnum(x,y,num);

    if(!flag&&mine){
        mp[x][y]='*';
        dfs(num+1,mine-1);
    }
    if(!flag&&n*m-num-1>=mine){
        mp[x][y]='.';
        dfs(num+1,mine);
    }

}
int main()
{
    //freopen("C://Users//Jo//Downloads//C-small-attempt0.in","r",stdin);
    //freopen("d://out.txt","w",stdout);
    int t;
    int mine;

    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d%d",&n,&m,&mine);
        flag=0;
        dfs(0,mine);
        printf("Case #%d:\n",cas);
        if(flag){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%c",mp[i][j]);
                }
                printf("\n");
            }
        }
        else printf("Impossible\n");
    }
    return 0;
}
