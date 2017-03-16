#include <stdio.h>
#include <stdlib.h>

int next(int a,int digits){
  int i,j;

  i=a%10;
  a/=10;
  for (j=1;j<digits;j++) i*=10;
  a+=i;
  return a;
}

main(){
  int T,tcase,A,B,digits,j,i,k,a,sum;
  FILE * f;
  FILE * g;
  int check[2000001];

  f=fopen("C.in","r");
  g=fopen("C.txt","w");

  fscanf(f,"%d\n",&T);
  for (tcase=1;tcase<=T;tcase++){
    fscanf(f,"%d %d\n",&A,&B);
    sum=0;
    digits=1;
    j=A;
    while(j=j/10) digits++;
    for (i=A;i<=B;i++){
      check[i]=0;
    }
    for (i=A;i<=B;i++){
      if (check[i]) continue;
      k=1;
      a=i;
      while ((a=next(a,digits))!=i){
	if (a<A||a>B) continue;
	check[a]=1;
	k++;
      }
      sum+=(k*(k-1)/2);
    }    
    fprintf(g,"Case #%d: %d\n",tcase,sum);
  } 

}
