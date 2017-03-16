#include <iostream>
#include <cstdio>
#include <map>
#define MAXN 505
using namespace std;

int testcase,S[MAXN],N,t,t1,t2;
map <int,int> M;
bool flag;

int main(){
  freopen("C-small-attempt0.in","r",stdin);
  freopen("C.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%d",&N);
    for(int i=0;i<N;++i) scanf("%d",&S[i]);
    M.clear();
    flag = 0;
    printf("Case #%d:\n",TC);
    for(int a=1;a<(1<<N);++a){
      t = 0;
      for(int i=0;i<N;++i) t += ((a&(1<<i)) > 0) * S[i];
      if(M.find(t) == M.end()) M[t] = a;
      else{
        flag = 1;
        t1 = M[t], t2 = a;
        for(int i=0;i<N;++i)
          if( (t1&(1<<i)) > 0 && (t2&(1<<i)) == 0) printf("%d ",S[i]);
        printf("\n");
        for(int i=0;i<N;++i)
          if( (t1&(1<<i)) == 0 && (t2&(1<<i)) > 0) printf("%d ",S[i]);
        printf("\n");
        break;
      }
    }
    if(!flag) printf("Impossible\n");
  }
}
