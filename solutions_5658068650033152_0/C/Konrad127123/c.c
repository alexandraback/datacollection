#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MOD 1000000007LL
int t,T,N;
int ans,M,K;
int tmp;

int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&N);
scanf("%d",&M);
scanf("%d",&K);

if (N>M) {tmp=N; N=M; M=tmp;}
/*Assume M is smaller*/ 



  if ((M==4)&&(N==5)) {
  /*printf("DD %d %d %d\n",N,M,K);*/
  ans=K;
  if (K>=5) ans--;
  if (K>=8) ans--;
  if (K>=10) ans--;
  if (K>=12) ans--;
  if (K>=14) ans--;
  if (K>=16) ans--;
 }

  if ((M==4)&&(N==4)) {
   ans=K;
   if (K>=5) ans--;
   if (K>=8) ans--;
   if (K>=10) ans--;
   if (K>=12) ans--;
  }

if (M==3) {
  ans=K;
  if ((K >= 5) && (N >=3)) ans--;
  if ((K >= 8) && (N >=4)) ans--;
  if ((K >= 11) && (N >=5)) ans--;
  if ((K >= 14) && (N >=6)) ans--;
 }

if ((N==1)||(N==2)||(M==1)||(M==2)) {ans=K;}

printf("Case #%d: ",t);
printf("%d\n",ans);

/*printf("D %d %d %d %d\n",N,M,K,K-ans);*/
}
return 0;
}
