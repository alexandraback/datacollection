#include <stdio.h>

main(){
  int T,tci,A,B,i,j,k,l;
  float chanc[100000],min,sum,prob;
  FILE *f;
  FILE *g;

  f=fopen("A.in","r");
  g=fopen("A.txt","w");

  fscanf(f,"%d\n",&T);
  for (tci=0;tci<T;tci++){
    fscanf(f,"%d %d",&A,&B);
    for(i=0;i<A;i++){
      fscanf(f,"%f",&chanc[i]);
      printf("%f\n",chanc[i]);
    }
    
    min=1.0+B+1;
    for(i=0;i<=A;i++){
      prob=1.0;
      for(j=0;j<A-i;j++){
	prob*=chanc[j]+0.0;
      }
      sum=i+0.0+prob*(B-A+i+1.0)+(1-prob)*(B-A+i+1+B+1);
      printf("%f\n",sum);
      if (sum<min) min=sum;
    }
    
    fprintf(g,"Case #%d: %f\n",tci+1,min);
  }
  fclose(f);
  fclose(g);
  return 0;
}
