#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAXN 1000
using namespace std;
vector<int> next[MAXN+10];
vector<int> pre[MAXN+10];
int vis[MAXN+10];
int CAS,N;
int dfs(int v)
{
    if(vis[v] == 1) return 0;
    vis[v] = 1;
    for(int i = 0;i < next[v].size();i++)
        dfs(next[v][i]);
    return 0;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&CAS);
    for(int cas = 1;cas <= CAS;cas++ )
    {
        scanf("%d",&N);
        for(int i = 0;i < N;i++)
        {
            next[i].clear();
            pre[i].clear();
        }
        for(int i = 0;i < N;i++)
        {
            int M;
            scanf("%d",&M);
            for(int j = 0;j < M;j++)
            {
                int t;
                scanf("%d",&t);
                t--;
                next[i].push_back(t);
                pre[t].push_back(i);
            }
        }

        bool flag = false;
        for(int i = 0;i < N && !flag;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i);
            for(int j = 0;j < N && !flag;j++)
            {
                if(vis[j] == 0) continue;
                int cnt = 0;
                for(int k = 0;k < pre[j].size();k++)
                {
                    if(vis[pre[j][k]] == 1) cnt++;
                }
                if(cnt >= 2)
                {
                    flag = true;
                    break;
                }
            }
        }
        printf("Case #%d: ",cas);
        if(flag)
            printf("Yes\n");
        else printf("No\n");
    }
    fclose(stdin);
    fclose(stdout);
}
