#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main(){

  int T, t, A, B, i;
  double p, P, M[4], mx;

  scanf("%d", &T);
  for(t=1; t<=T; t++){
    scanf("%d%d", &A, &B);
    P=1;
    M[0]=B+2;
    if(A<=2) M[1]=3+B;
    if(A==1) M[2]=2+B;
    for(i=0; i<A; i++){
      scanf("%lf", &p);
      P*=p;
      if(i==A-3) M[1]=P*(5+B-A) + (1-P)*(5+B-A+B+1);
      if(i==A-2) M[2]=P*(3+B-A) + (1-P)*(3+B-A+B+1);
    }
    M[3]=P*(B-A+1) + (1-P)*(2*B-A+2);
    mx=M[0];
    for(i=1; i<4; i++) if(M[i]<mx) mx=M[i];
    printf("Case #%d: %.6lf\n", t, mx);
      
  }

  return 0;
}
