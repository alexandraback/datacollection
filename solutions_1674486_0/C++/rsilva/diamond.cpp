#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 1001
int adj[MAXN][MAXN], nadj[MAXN];
int used[MAXN];

bool dfs(int n) {
      if(used[n] == 1) return true;    
      used[n] = 1;
      //printf("%d ",n);
      for(int i = 0;i < nadj[n];i++) {
              if(dfs(adj[n][i])) return true;     
                   
      }
     // printf("***\n",n);
      return false;
}     

int main() {
    int t;
    scanf("%d",&t);
    for(int k = 0;k < t;k++) {
        memset(nadj,0,sizeof(nadj));
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d",&m);
            for(int j = 0;j < m;j++) {
                int to;
                scanf("%d",&to);        
                adj[i][nadj[i]++] = to-1;
            }
        }
        int i;
        for(i = 0;i < n;i++) {
           memset(used,0,sizeof(used));   
           if(dfs(i)) {
               printf("Case #%d: Yes\n",k+1);
               break;  
            }
        }
        if(i == n)  printf("Case #%d: No\n",k+1);
    }
    return 0;
}
