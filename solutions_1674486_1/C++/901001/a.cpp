#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
//short num[1001][1001];
//int in[1001];
bool flag;
vector<int>res[1001];
int vis[1001];
void dfs(int t) {
  //printf("%d\n",t);
  if(flag)return ;
  vis[t]++;
  if(vis[t]>1) {
    flag=true;
    return ;
  }
  for(int i=0;i<res[t].size();i++) {
    dfs(res[t][i]);
  }
}
int main() {
  //freopen("A-small-attempt1.in","r",stdin);
  //freopen("A-small-attempt1.out","w",stdout);
  freopen("A-large.in","r",stdin);
  freopen("A-large.out","w",stdout);
  int cas,n,cnt;
  scanf("%d",&cas);

  for(int t=1;t<=cas;t++) {
    scanf("%d",&n);
    //memset(in,0,sizeof(in));

    for(int i=1;i<=n;i++) {
      res[i].clear();
      scanf("%d",&cnt);
      for(int j=1;j<=cnt;j++) {
        int tmp;
        scanf("%d",&tmp);
        res[i].push_back(tmp);
        //in[tmp]++;
      }
    }
    flag=false;
    for(int i=1;i<=n;i++) {
      //if(in[i]==0) {
        memset(vis,0,sizeof(vis));

        dfs(i);
        //printf("fadsda%d\n",vis[5]);
      //}
    }
    if(flag) {
      printf("Case #%d: Yes\n",t);
    } else {
      printf("Case #%d: No\n",t);
    }
  }
  return 0;
}
