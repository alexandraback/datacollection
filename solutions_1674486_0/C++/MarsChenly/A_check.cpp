/*
Author:MarsChenly
Date:2012.05.06
*/

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn(1005);

int first[maxn];

struct rec
{
      int y,next;
} g[maxn * maxn * 2];

int tot,n;
int mark[maxn];
bool visit[maxn];

void add(int x,int y)
{
      tot++;
      g[tot].y = y; 
      g[tot].next = first[x];
      first[x] = tot;
}

int node = 0;
int edge = 0;

bool dfs(int x)
{
      if (visit[x]) return true;
      visit[x]  = true;
      node++;
      int p = first[x];
      while (p)
      {
            int y = g[p].y;
            edge++;
            if (dfs(y)) return true;
            p = g[p].next;
      }
      return false;
}

bool tree(int x)
{
      node = 0;
      edge = 0;
      dfs(x);
      edge = edge / 2;
      if (edge == node - 1) return true;
      return false;
}

int main()
{
      freopen("A.in","r",stdin);
      freopen("A_check.out","w",stdout);
      int task;
      scanf("%d",&task);
      for (int cases = 1; cases <= task; cases++)
      {
            scanf("%d",&n);
            memset(first,0,sizeof(first));
            tot = 0;
            for (int i = 1; i <= n; i++)
            {
                  int k,x;
                  scanf("%d",&k);
                  for (int j = 1; j <= k; j++)
                  {
                        scanf("%d",&x);
                        add(i,x);
//                        add(x,i);
                  }
            }
            memset(visit,0,sizeof(visit));
            bool flag = false;
            for (int i = 1; i <= n; i++)
//            if (!visit[i])
            {
                  memset(visit,0,sizeof(visit));
                  if (dfs(i))
                  {
                        flag = true;
                        break;
                  }
            }
            printf("Case #%d: ",cases);
            if (flag == true)
            {
                  printf("Yes\n");
            } else 
            {
                  printf("No\n");
            }
      }
      return 0;
}
