#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
int t,x,y,vis[205][205];
char map[205][205][505];
int pos(int x){return x+100;}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int amm=1;amm<=t;amm++)
    {
        scanf("%d%d",&x,&y);
        memset(vis,0,sizeof(vis));
        queue<ii> q;
        q.push(ii(pos(0),pos(0)));
        vis[pos(0)][pos(0)]=1;
        int now=1;
        while(1)
        {
            if(vis[pos(x)][pos(y)])break;
            ii tmp=q.front();
            q.pop();
            now=strlen(map[tmp.first][tmp.second])+1;
            if(tmp.first+now<=pos(100))
            {
                if(!(vis[tmp.first+now][tmp.second] && strlen(map[tmp.first][tmp.second])+1>=strlen(map[tmp.first+now][tmp.second])))
                {
                    q.push(ii(tmp.first+now,tmp.second));
                    vis[tmp.first+now][tmp.second]=1;
                    strcpy(map[tmp.first+now][tmp.second],map[tmp.first][tmp.second]);
                    strcat(map[tmp.first+now][tmp.second],"E");
                }
            }
            if(tmp.first-now>=pos(-100))
            {

                if(!(vis[tmp.first-now][tmp.second] && strlen(map[tmp.first][tmp.second])+1>=strlen(map[tmp.first-now][tmp.second])))
                {
                    q.push(ii(tmp.first-now,tmp.second));
                    vis[tmp.first-now][tmp.second]=1;
                    strcpy(map[tmp.first-now][tmp.second],map[tmp.first][tmp.second]);
                    strcat(map[tmp.first-now][tmp.second],"W");
                }
            }
            if(tmp.second+now<=pos(100))
            {

                if(!(vis[tmp.first][tmp.second+now] && strlen(map[tmp.first][tmp.second])+1>=strlen(map[tmp.first][tmp.second+now])))
                {
                    q.push(ii(tmp.first,tmp.second+now));
                    vis[tmp.first][tmp.second+now]=1;
                    strcpy(map[tmp.first][tmp.second+now],map[tmp.first][tmp.second]);
                    strcat(map[tmp.first][tmp.second+now],"N");
                }
            }
            if(tmp.second-now>=pos(-100))
            {

                if(!(vis[tmp.first][tmp.second-now] && strlen(map[tmp.first][tmp.second])+1>=strlen(map[tmp.first][tmp.second-now])))
                {
                    q.push(ii(tmp.first,tmp.second-now));
                    vis[tmp.first][tmp.second-now]=1;
                    strcpy(map[tmp.first][tmp.second-now],map[tmp.first][tmp.second]);
                    strcat(map[tmp.first][tmp.second-now],"S");
                }
            }
        }
        //printf("aaa");
        printf("Case #%d: %s\n",amm,map[pos(x)][pos(y)]);
    }
    return 0;
}
