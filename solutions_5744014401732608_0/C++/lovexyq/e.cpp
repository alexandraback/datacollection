#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstdio>
#include<ctime>
#include<queue>
using namespace std;
int n,m;
const int maxn = 52;
vector<int> zz[maxn];
int dp[maxn],ct[maxn],vis[maxn];
int ed[5000][2],esize;
int matrix[maxn][maxn];
void generate(){
  esize=0;
  for(int i=1;i<n;i++){
    for(int j=i+1;j<=n;j++){
      ed[esize][0]=i;
      ed[esize][1]= j;
      esize++;
    }
  }
}
void create(int st){
  memset(matrix,0,sizeof(matrix));
  for(int i=0;i<esize;i++){
    if(st&(1<<i)){
      zz[ed[i][0]].push_back(ed[i][1]);
      matrix[ed[i][0]][ed[i][1]]=1;
      ct[ed[i][1]]++;
    }
  }
}
void reset(){
  for(int i=0;i<=n;i++){
    zz[i].clear();
    dp[i]=0;
    ct[i]=0;
  }
}
bool cal(){
  zz[0].push_back(1);
  dp[0]=1;
  ct[1]=1;
  queue<int> q;
  q.push(0);
  vis[0]=1;
  while(q.size()){
    int t = q.front();
    for(int i=0;i<zz[t].size();i++){
      int k= zz[t][i];
      ct[k]--;
      dp[k] += dp[t];
      if(ct[k]==0){
        q.push(k);
      }
    }
    q.pop();
  }
  if(dp[n]==m){
    return true;
  }
  return false;
}
void out(){
          for(int j=1;j<=n;j++){
          for(int k=1;k<=n;k++){
            if(matrix[j][k]){
              printf("1");
            }else {
              printf("0");
            }
          }
          printf("\n");
        }
}
int main(){
  int T;
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++){
    scanf("%d%d",&n,&m);
    printf("Case #%d: ",cas);
    generate();
    bool res = false;
    for(int i=1;i<(1<<esize);i++){
      reset();
      create(i);
      //out();
      res = cal();
      if(res==true){
        printf("POSSIBLE\n");
        out();
        break;
      }
    }
    if(res==false){
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}