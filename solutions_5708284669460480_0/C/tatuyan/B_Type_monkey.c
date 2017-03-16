#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
  char target[101],types[101];
  unsigned Key,S,L,T,tt;
  int i,j,k,l,nowmax;
  long double P[101][101][101],per[101],exps;

  scanf("%u%*c",&T);
  for(tt=1;tt<=T;tt++){
    scanf("%u%u%u%*c",&Key,&L,&S);
    scanf("%s%*c",types);
    scanf("%s%*c",target);

    memset(per,0,sizeof(per));
    for(i=0;i<L;i++) for(j=0;j<Key;j++) if(types[j]==target[i]) per[i]++;
    for(i=0;i<L;i++) per[i]/=(long double)Key;

    memset(P,0,sizeof(P));
    P[0][0][0]=1;
    nowmax=0;
    for(i=1;i<=S;i++){
      for(j=0;j<L;j++){
	if(j==0){
	  for(k=0;k<=nowmax+1;k++){
	    for(l=0;l<L;l++){
	      P[i][j][k]+=(1-per[l])*P[i-1][l][k];
	    }
	    if(k!=0) P[i][j][k]+=per[L-1]*P[i-1][L-1][k-1];
	  }
	  if(P[i][0][nowmax+1]!=0) nowmax++;
	}else{
	  for(k=0;k<=nowmax;k++){
	    P[i][j][k]=per[j-1]*P[i-1][j-1][k];
	  }
	}
      }
    }
    exps=0;
    for(j=0;j<L;j++) for(k=1;k<=nowmax;k++) exps+=P[S][j][k]*k;

    printf("Case #%u: %.9Lf\n",tt,nowmax-exps);
  }

  return 0;
}
