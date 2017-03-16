#include <stdio.h>

main(){
  int T,tci,N,preq[1000][2],i,j,k,stars,games,added,imax;
  FILE *f;
  FILE *g;

  f=fopen("B.in","r");
  g=fopen("B.txt","w");

  fscanf(f,"%d\n",&T);
  for (tci=0;tci<T;tci++){
    stars=games=0;
    fscanf(f,"%d",&N);
    for(i=0;i<N;i++){
      fscanf(f,"%d %d",&preq[i][0],&preq[i][1]);
    }
    added=1;
    while(added){
      added=0;
      for(i=0;i<N;i++){
	if (preq[i][1]!=-1&&stars>=preq[i][1]){
	  games++;
	  added=1;
	  if (preq[i][0]==-1) {
	    stars+=1; 
	  } else {
	    stars+=2;
	  }
	  preq[i][0]=preq[i][1]=-1;
	}
      }
      if(!added){
	imax=-1;
	for(i=0;i<N;i++){
	  if (preq[i][0]!=-1&&stars>=preq[i][0]){
	    if (imax==-1) imax=i;
	    if (preq[i][1]>preq[imax][1]) imax=i;
	  }
	  
	}
	if (imax!=-1){
	  games++;
	  added=1;
	  preq[imax][0]=-1;
	  stars++;
	}
      }
    }
    for(i=0;i<N;i++){
      if (preq[i][1]!=-1) stars=-1;
    }
    if (stars!=-1){
      fprintf(g,"Case #%d: %d\n",tci+1,games);
    }	  
    else {
      fprintf(g,"Case #%d: Too Bad\n",tci+1);
    }
  }
  fclose(f);
  fclose(g);
  return 0;
}
