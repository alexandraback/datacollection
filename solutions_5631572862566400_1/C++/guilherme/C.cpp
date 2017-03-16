#include <cstdio>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
int bff[1234];
vector<int> invbff[1234];
int n;
int ret;
int foi[1234];
int acc;
int solve(int a){
  memset(foi,0,sizeof(foi));
  int x=a;
  int ret = 0;
  while(foi[x]==0){
    foi[x]=1;
    x=bff[x];
    ret++;
  }
  if(x==a)return ret;
  return 0;
}
int calc_max(int a,int b){
  int ret = 0;
  for(int i=0;i<(int)invbff[a].size();i++){
    int x = invbff[a][i];
    if (x==b)continue;
    ret = max(ret,calc_max(x,b));
  }
  return 1+ret;
}
int main(){
  int tt;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++){
    scanf("%d",&n);
    ret = acc = 0;
    for(int i=0;i<n;i++){
      invbff[i].clear();
    }
    for(int i=0;i<n;i++){
      scanf("%d",&bff[i]);
      bff[i]--;
      invbff[bff[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
      ret = max(ret, solve(i));
      //      printf("%d %d\n",i,solve(i));
    }
    for(int i=0;i<n;i++){
      if (bff[bff[i]]==i){
	acc += calc_max(i,bff[i]);
      }
    }
    printf("Case #%d: %d\n", rr,max(ret,acc));
  }
  return 0;
}
