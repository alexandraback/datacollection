#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
  int tc, N, S, p, score;
  int ans;
  scanf("%d",&tc);
  for(int ks=1; ks <= tc; ks++){
    ans = 0;
    scanf("%d%d%d",&N,&S,&p);
    for(int i=0; i<N; i++){
      scanf("%d",&score);
      if(p == 0) ans ++;
      else if(p>0 && score >= 3*p -2) ans ++;
      else if(p>1 && score >= 3*p - 4 && S > 0) {
	ans ++;
	S--;
      }
    }
    printf("Case #%d: %d\n",ks,ans);
  }
  return 0;
}
