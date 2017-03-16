#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

bool graph[1002][1002];
int par[1002];
int ntest,n;

bool doBFS(int start){
     queue<int> Q;
     for (int i=0;i<n;++i) par[i]=-1;
     Q.push(start);
     int now;
     
     while (!Q.empty()){
           now=Q.front();
           Q.pop();
           for (int i=0;i<n;++i){
               if (graph[now][i] && par[i]==-1){
                  par[i]=now;
                  Q.push(i);
               }
               else if (graph[now][i] && par[i]!=-1){
                    par[i]+=2000*(1+now);
                    Q.push(i);
               }
           }
     }
     for (int i=0;i<n;++i){
         if (par[i]>1000) return 1;
     }
     return 0;
}
int main(){
    int m,temp;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        scanf("%d",&n);
        memset(graph,0,sizeof(graph));
        for (int i=0;i<n;++i){
            scanf("%d",&m);
            for (int j=0;j<m;++j){
                scanf("%d",&temp);
                graph[i][temp-1]=1;
            }
        }
        bool inherit=0;
        for (int start=0;start<n;++start){
            inherit=doBFS(start);
            if (inherit){
               printf("Case #%d: Yes\n",test);
               break;
            }
        }
        if (!inherit)
           printf("Case #%d: No\n",test);
    }
    return 0;
}
