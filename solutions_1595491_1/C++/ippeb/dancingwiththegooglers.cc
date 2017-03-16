#include <cstdio>
#include <iostream>
using namespace std;

int T,p,S,N,A[201],sol;
int a,b;

int main(){
  scanf("%d",&T);
  for (int t=1; t<=T; t++){
    sol=0;
    scanf("%d %d %d",&N,&S,&p);
    for (int i=0; i<N; i++) scanf("%d",&A[i]);
    for (int i=0; i<N; i++){
      if (A[i]%3==0) a=A[i]/3;
      else a=A[i]/3+1;
      if (A[i]%3==2) b=A[i]/3+2;
      else b=A[i]/3+1;

      if (A[i]<3){
	if (A[i]==0){a=0; b=0;}
	if (A[i]==1){a=1; b=1;}
	if (A[i]==2){a=1; b=2;}
      }
      
      if (a>=p) sol++;
      else if (b>=p && S>0){
	sol++;
	S--;
      }
    }
    printf("Case #%d: %d\n",t,sol);
  }
}
