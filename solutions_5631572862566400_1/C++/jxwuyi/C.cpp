#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

const int MaxN = 1012;
int T[MaxN];
int N;

int dis[MaxN];// dist to circle
int id[MaxN]; // circle id
vector<int> cir[MaxN]; // circles
int S; // #circles

int vis[MaxN];

int best[MaxN];

int run() {
  scanf("%d", &N);
  for(int i=1;i<=N;++i)scanf("%d",T+i);
  memset(vis,-1,sizeof(vis));
  memset(id,-1,sizeof(id));
  memset(dis,-1,sizeof(dis));
  memset(best,0,sizeof(best));
  S=0;
  int ans = 0;
  // find circles
  for(int i=1;i<=N;++i){
    if(id[i] > -1) continue; // already marked
    int x= i;
    vis[i] = i;
    for(x = T[x]; vis[x] != i; x = T[x]) vis[x] = i;
    if(x != i) continue;
    cir[S].clear();
    for(int j=1;j<=N;++j)
      if(vis[j]==i){
        id[j]=S;
        cir[S].push_back(j);
        dis[j] = 0;
        best[j] = 0;
      }
    // answer of a single circle
    if(cir[S].size() > ans) ans = cir[S].size();
    ++ S;
  }
  // compute distances
  for(int i=1;i<=N;++i){
    if(id[i]>-1)continue;
    int x = i;
    int cnt=0;
    for(; dis[x] != 0; x = T[x], ++ cnt);
    dis[i] = cnt;
    id[i] = id[x];
    best[x] = max(best[x], cnt);
  }
  int rem=0;
  // answer = 2-circle + two chains
  for(int i=1;i<=N;++i)
    if(dis[i] == 0 && cir[id[i]].size()==2) {
      int j = T[i]; // 2-circle i<->j
      assert(T[j]==i);
      if(j < i) continue;
      rem += 2 + best[i] + best[j];
    }
  
  return max(ans, rem);
}

int main() {
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  int test;scanf("%d",&test);
  for(int no=1;no<=test;++no){
    printf("Case #%d: %d\n", no, run());
  }
}
