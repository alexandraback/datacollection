#include <stdio.h>
#include <stdlib.h>

main(){
  int tcase,T,S,t,N,i,p,total;
  char c;
  FILE * f;
  FILE * g;

  f=fopen("B.in","r");
  g=fopen("B.txt","w");

  fscanf(f,"%d\n",&T);
  for (tcase=1;tcase<=T;tcase++){
    fprintf(g,"Case #%d: ",tcase);
    total=0;
    fscanf(f,"%d ",&N);
    fscanf(f,"%d ",&S);
    fscanf(f,"%d",&p);
    for (i=0; i<N;i++){
      fscanf(f," %d",&t);
      if (t/3>=p){
	total++;
	continue;

      }
      if (p-t/3>=3) continue;
      if ((p-t/3==1)&&(t%3!=0)){
	total++;
	continue;
      }
      if ((p-t/3==1)&&t>0&&S>0){
	S--;
	total++;
	continue;
      }
      if ((t%3==2)&&(S>0)){
	S--;
	total++;
      }
 
    }
    fprintf(g,"%d\n",total);

  }


}
