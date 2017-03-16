#include <iostream>
#include <cstdio>
using namespace std;

int testcase,N,M;
int B[105][105];
bool can;

int main(){
  freopen("B-small-attempt0.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%d%d",&N,&M);
    can = 1;
    for(int i=0;i<N;++i)
      for(int j=0;j<M;++j) scanf("%d",&B[i][j]);
    for(int i=0;i<N;++i)
      for(int j=0;j<M;++j){
        int t1 = B[i][j], t2 = B[i][j];
        for(int k=0;k<N;++k) t1 = max(t1,B[k][j]);
        for(int k=0;k<M;++k) t2 = max(t2,B[i][k]);
        can &= (t1 <= B[i][j] || t2 <= B[i][j]);
      }
    printf("Case #%d: %s\n",TC,(can)?"YES":"NO");
  }
}
