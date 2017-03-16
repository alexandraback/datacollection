#include <stdio.h>

main(){
  int T,i,j,k,tci,N,s[200],v[200],sum,total,found,min,souts,nouts;
  FILE *f;
  FILE *g;

  f=fopen("A.in","r");
  g=fopen("A.txt","w");

  fscanf(f,"%d\n",&T);
  for (tci=0;tci<T;tci++){
	fscanf(f,"%d",&N);
	sum=0;
	for (i = 0 ; i < N ; i++){
		fscanf(f,"%d",&(s[i]));
		sum+=s[i];
		v[i]=0;
	}
	souts=nouts=0;
	for(i=0;i<N;i++){
		total=0;
		for (j=0;j<N;j++){
			k=s[i]-s[j];
			if (k>0) total+=k;
		}
		if (total>=sum){
			v[i]=1;
			souts+=s[i];
			nouts++;
		}
	}
	

    fprintf(g,"Case #%d:",tci+1);
	for(i=0;i<N;i++){
		if (v[i]) {fprintf(g," %f",0.0);continue;}
		fprintf(g," %f",(( (2.0*sum-souts)/(N-nouts) )-s[i])*100.0/sum);
	}


	fprintf(g,"\n");
  }
  fclose(f);
  fclose(g);
  return 0;
}
