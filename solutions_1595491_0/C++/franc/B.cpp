#include <stdio.h>

using namespace std;

int main(){

  int T, N, S, p, t, i, ncase, cnt;
  int M1, M2;
  scanf("%d", &T);
  for(ncase=1; ncase<=T; ncase++){
    cnt=0;
    scanf("%d%d%d", &N, &S, &p);
    M1=3*p-2;
    M2=3*p-4;
    if(p==1) M2=1;
    for(i=0; i<N; i++){
      scanf("%d", &t);
      if(t>=M1) cnt++;
      else if(t>=M2 && S){ cnt++; S--;}
    }
    printf("Case #%d: %d\n", ncase, cnt);
  }
 
  return 0;
}
