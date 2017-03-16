#include <iostream>
#include <cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 1 << 10;

int n;
vector<int> e[MAXN];
bool vis[MAXN];

bool check()
{
    for(int i = 0; i < n; i ++)
    {
        queue<int> que;
        memset(vis, false, sizeof(vis));
        que.push(i);
        vis[i]=1;

        while(!que.empty())
        {
            int u = que.front();
			que.pop();
            for(int j = 0; j < e[u].size(); j ++)
            {
                int v = e[u][j];
                if(!vis[v])
                {
                    vis[v] = true;
                    que.push(v);
                }
                else
                   return true;
            }
        }
    }

    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 1; t <= T; t ++)
    {
        scanf("%d",&n);
        for(int i = 0; i < MAXN; i ++){
			e[i].clear();
		}

        for(int i = 0; i < n; i ++)
        {
			int cnt, v;
            scanf("%d",&cnt);
            for(int j = 0; j < cnt; j ++){
              scanf("%d", &v);
			  v --;
              e[i].push_back(v);
            }
        }

        if(check())
            printf("Case #%d: Yes\n", t);
        else
           printf("Case #%d: No\n", t);
    }

    return 0;
}

