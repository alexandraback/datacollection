#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <set>
using namespace std;
typedef long long ll;

#define P make_pair
typedef pair<int,int> txy;
typedef pair<ll,txy> tpxy;
typedef priority_queue<tpxy> tpq;

ll up[200][200];
ll dn[200][200];

ll best[200][200];
ll can[200][200];

static ll const dx[]={-1,0,1,0};
static ll const dy[]={0,-1,0,1};
ll woff,n,m,water;

inline bool ok(int x,int y, int u,int v){
  if (u>=0 and v>=0 and u<n and v<m){
    ll f1=max(dn[x][y],water);
    ll f2=max(dn[u][v],water);
    if (max(f1,f2)+50ll<=up[u][v]){
      if (dn[u][v]+50ll<=up[x][y]){
        return true;
      }
    }
  }
  return false;
}

inline bool mock(int x,int y, int u,int v){
  ll temporary=water; water=-50000ll;
  bool res=ok(x,y,u,v);
  water=temporary;
  return res;
}

int main(){
//  freopen("B.in","r",stdin);
  int tests; cin>>tests; for (int test=1; test<=tests; test++){

    cin>>woff>>n>>m; 
    for (int i=n; i--;) for (int j=m; j--;) best[i][j]=-(1ll<<40ll), can[i][j]=false;
    water=woff;

    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
        cin>>up[i][j];

    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
        cin>>dn[i][j];

    can[0][0]=true;
    vector<txy> bfs; bfs.push_back(P(0,0));
    for (int i=0; i<bfs.size(); i++){
      int x=bfs[i].first, y=bfs[i].second;
      for (int j=4; j--;){
        if (ok(x,y,x+dx[j],y+dy[j]) and not can[x+dx[j]][y+dy[j]]){
          bfs.push_back(P(x+dx[j],y+dy[j]));
          can[x+dx[j]][y+dy[j]]=true;
        }
      }
    }

    tpq todo;
    for (int i=n; i--;)
      for (int j=m; j--;)
        if (can[i][j])
          best[i][j]=woff, todo.push(P(woff,P(i,j)));

    while (not todo.empty()){
      int x=todo.top().second.first;
      int y=todo.top().second.second;
      ll now=water=best[x][y];
      todo.pop();

      for (int j=4; j--;){
        if (true){
          ll l=-1, r=now+1;
          while (l+1<r){
            water=(l+r)/2ll;
            if (ok(x,y,x+dx[j],y+dy[j])) l=water; else r=water;
          }
          if (l!=-1){
            if (l>=dn[x][y]+20ll){
              l-=10ll;
            }else{
              l-=100ll;
            }
            if (l>best[x+dx[j]][y+dy[j]]){
              best[x+dx[j]][y+dy[j]]=l;
              todo.push(P(l,P(x+dx[j],y+dy[j])));
            }
          }
        }
      }
    }
    printf("Case #%d: %lld.%01lld\n",test,(woff-best[n-1][m-1])/10ll,(woff-best[n-1][m-1])%10ll);
  }
}
