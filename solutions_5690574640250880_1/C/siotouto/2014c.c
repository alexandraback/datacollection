#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define FALSE 0
#define TRUE 1

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int main(void)
{
  int i,j,k,t,T,R,C,M,safe;
  char mine[64][64];
  scanf("%d",&T);
  t=T;
  while(t--){
    printf("Case #%d:\n",T-t);
    scanf("%d %d %d",&R,&C,&M);
    safe=R*C-M;
    if(R==1){
      for(i=0;i<C;i++){
	if(i<safe) mine[0][i]='.';
	else mine[0][i]='*';
      }
    }else if(C==1){
      for(j=0;j<R;j++){
	if(j<safe) mine[j][0]='.';
	else mine[j][0]='*';
      }
    }else if(R==2){
      if((safe!=1&&safe%2)||safe==2){
	printf("Impossible\n");
	continue;
      }else{
	for(j=0;j<R;j++)
	  for(i=0;i<C;i++){
	    if(i<safe/2) mine[j][i]='.';
	    else mine[j][i]='*';
	  }
      }
    }else if(C==2){
      if((safe!=1&&safe%2)||safe==2){
	printf("Impossible\n");
	continue;
      }else{
	for(j=0;j<R;j++)
	  for(i=0;i<C;i++){
	    if(j<safe/2) mine[j][i]='.';
	    else mine[j][i]='*';
	  }
      }
    }else{
      if(safe==2||safe==3||safe==5||safe==7){
	printf("Impossible\n");
	continue;
      }else{
	if(1<safe&&safe<C*2+2){
	  if(safe%2){
	    safe-=3;
	    for(j=0;j<R;j++)
	      for(i=0;i<C;i++){
		if((i<safe/2&&j<2)||i<3&&j==2) mine[j][i]='.';
		else mine[j][i]='*';
	      }
	  }else{
	    for(j=0;j<R;j++)
	      for(i=0;i<C;i++){
		if(i<safe/2&&j<2) mine[j][i]='.';
		else mine[j][i]='*';
	      }
	  }
	}else{
	  for(j=0;j<R;j++)
	    for(i=0;i<C;i++){
	      if(j*C+i<safe) mine[j][i]='.';
	      else mine[j][i]='*';
	    }
	  if(safe%C==1&&safe/C>=3){
	    mine[safe/C-1][C-1]='*';
	    mine[safe/C][1]='.';
	  }
	}
      }
    }
    mine[0][0]='c';
    for(j=0;j<R;j++){
      for(i=0;i<C;i++) printf("%c",mine[j][i]);
      printf("\n");
    }
  }
  return 0;
}
