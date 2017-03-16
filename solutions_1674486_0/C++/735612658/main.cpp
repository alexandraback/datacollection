#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1005;
struct  EDGE
 {
     int v,next;
 }edge[N*10];
 int head[N],n,num,d[N];
 bool  used[N];
 void add(int a,int b)
  {
      edge[num].v = b;
      edge[num].next = head[a];
      head[a] = num++;
  }
 bool dfs(int u)
  {
      for(int i = head[u];i != -1;i = edge[i].next)
       {
           int v = edge[i].v;
           if(used[v]) return true;
           used[v] = true;
           if(dfs(v))
            return true;
       }
     return false;
  }
 int main()
  {
      //freopen("A-small-attempt0.in","r",stdin);
      //freopen("t.txt","w",stdout);
      int t;
      scanf("%d",&t);
      for(int k = 1;k <= t;k++)
       {
           scanf("%d",&n);
           int x;
           num = 0;
           memset(head,-1,sizeof(head));
           for(int i = 1;i <= n;i++)
             {
                 scanf("%d",&d[i]);
                 for(int  j = 1;j <= d[i];j++)
                  {
                      scanf("%d",&x);
                      add(x,i);
                  }
             }
           bool flag = 0;
           for(int i = 1;i <= n;i++)
            {
                if(d[i] == 0)
                {
                    memset(used,0,sizeof(used));
                    used[i] = true;
                    if(dfs(i))
                     {
                         flag = true;
                         break;
                     }
                }
            }
            if(flag)
                 printf("Case #%d: Yes\n",k);
             else
               printf("Case #%d: No\n",k);
       }
       return 0;
  }
