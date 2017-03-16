#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int N = 1100;
struct node{
      int v;
      node *next;
} *adj[N],space[N*N];
int n,E,cnt;
bool visited[N];
void addEdge(int v,int u){
      node *p=&space[++E];
      p->v = u;
      p->next = adj[v];
      adj[v] = p;
}
void dfs(int v,int target){
      visited[v] = true;
      if (v == target) {cnt++; visited[v] = false; return ;}
      for (node *p=adj[v];p!=NULL;p=p->next){
            int u = p->v;
            if (!visited[u]) dfs(u,target);
      }
      visited[v] = false;
}
int main(){
     // freopen("test.in","r",stdin);
    //  freopen("test.out","w",stdout);
      int T;
      scanf("%d",&T);
      for (int t=1;t<=T;t++){
            bool flag = false;
            E = 0;
            memset(adj,NULL,sizeof(adj));
            scanf("%d",&n);
            for (int i=1;i<=n;i++){
                  int m,b; scanf("%d",&m);
                  for (int j=1;j<=m;j++){
                        scanf("%d",&b);
                        addEdge(i,b);
                  }
            }
            memset(visited,false,sizeof(visited));
            for (int i=1;i<=n;i++)
                  for (int j=n;j>=1;j--){
                        if (i==j) continue;
                        cnt = 0;
                        dfs(i,j);
                        if (cnt>1) {flag = true;break;}
                  }
            printf("Case #%d: ",t);
            if (flag) puts("Yes"); else puts("No");
      }
      return 0;
}
