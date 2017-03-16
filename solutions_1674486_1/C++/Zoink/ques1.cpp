using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

# define PI 3.14159265

int len[1010],vis[1010],found;
vector<int>adj[1010];


void bfs(int x) {
     int i,j,u,v;
     queue<int> q;
     
     q.push(x);
     vis[x]=1;
     while(!q.empty()) {
           u=q.front();
           q.pop();           
           for(i=0;i<len[u];i++) {
                   v=adj[u][i];            
                   if(vis[v]) { found=1; break; }
                   q.push(v);
                   vis[v]=1;
           }
           if(found==1) break;
     }
     return;
}

               
                           

     
     
     
int main() {
    int cs=0,x,i,j,v,u,t,n;
    scanf("%d",&t);
    while(t--) {
           scanf("%d",&n);
           cs++;
           found=0;
           for(i=1;i<=n;i++) { adj[i].clear(); vis[i]=0; len[i]=0;}
           
           for(i=1;i<=n;i++) {
                   scanf("%d",&x);
                   len[i]=x;
                   for(j=0;j<x;j++) {
                             scanf("%d",&v);
                             adj[i].push_back(v);
                   }
           }
           
           for(i=1;i<=n;i++) {
                   if(found==1) break;
                   for(j=1;j<=n;j++) vis[j]=0;      
                   bfs(i);
           }
           //cout<<"dsdsdsd";
           if(found==1) printf("Case #%d: Yes\n",cs);
           else printf("Case #%d: No\n",cs);
           
    }
    return 0;
}
