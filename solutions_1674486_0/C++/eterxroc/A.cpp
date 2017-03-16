#include <stdio.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

queue<int> q;
int d[1005];
int n,m;
int cnt;
int first[1005];
int vis[1005];

struct data
{
   int pos;
   int d;
} a[1005];

struct edge
{
   int from;
   int to;
   int next;
} e[200005];


int cmp(data a,data b)
{
    return a.d<b.d;
}

void add(int x,int y)
{
     e[cnt].from=x;
     e[cnt].to=y;
     e[cnt].next=first[x];
     first[x]=cnt;
     cnt++;
}

bool dfs(int k)
{
     if(vis[k]) return 1;
     vis[k]=1;
     for(int i=first[k];i!=-1;i=e[i].next)
     {
         if(dfs(e[i].to)) return 1;
     }
     return 0;
}

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("b.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d",&n);    
        cnt=0;
        memset(first,-1,sizeof(first));  
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) a[i].pos=i;
        
        for(int i=1;i<=n;i++)
        {
          int k;
          scanf("%d",&k);      
          for(int j=0;j<k;j++)
          {
             int w;
             scanf("%d",&w);
             a[w].d++;
             add(i,w);
          }
        }
        
        sort(a+1,a+n+1,cmp);
      //  for(int i=1;i<=n;i++) printf("%d %d\n",a[i].pos,a[i].d);
        
        bool is=false;
        for(int i=1;i<=n;i++)
           if(a[i].d) break;
           else
           {
              memset(vis,0,sizeof(vis));
              if(dfs(a[i].pos)) {is=true;break;}
           }
        
        if(!is) printf("Case #%d: No\n",ca); else printf("Case #%d: Yes\n",ca);
    }
}
    
