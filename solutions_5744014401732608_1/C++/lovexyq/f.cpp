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
int n;
long long m;
const int maxn = 52;
int matrix[maxn][maxn];
long long zz[52];
void init(){
  zz[0]=1;
  zz[1]=1;
  zz[2]=1;
  for(int i=3;i<=50;i++){
    zz[i]=zz[i-1]*2;
  }
}
bool cal(){
  memset(matrix,0,sizeof(matrix));
  if(m<=(1<<(n-2))){
    for(int i=1;i<n-1;i++){
      for(int j=i+1;j<=n-1;j++){
        matrix[i][j] = 1;
      }
    }
    if(m==(1<<(n-2))){
      for(int i=1;i<n;i++){
        matrix[i][n]=1;
      }
    } else {
      for(int i=n-1;i>=2;i--){
        //printf("%d %lld %lld\n",i,zz[i],m);
        if(zz[i]&m){
          matrix[i][n]=1;
        }
      }
    }
    return true;
  } else {
    return false;
  }
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
  init();
  for(int cas=1;cas<=T;cas++){
    scanf("%d%lld",&n,&m);
    printf("Case #%d: ",cas);
      //out();
      bool res = cal();
      if(res==true){
        printf("POSSIBLE\n");
        out();
      }else{
      printf("IMPOSSIBLE\n");
      }
  }
  return 0;
}