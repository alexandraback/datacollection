#include<stdio.h>

int main(void){
  int stars[3][10];
  int i,j,k,t,ti,n;
  int now,count,flg,next;
  
  scanf("%d",&t);
  for(ti=1;ti<=t;ti++){
    now=count=flg=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %d",&stars[1][i],&stars[2][i]);
      stars[0][i]=0;
    }

    while(flg==0){
      //printf("now=%d\n",now);
      for(i=0;i<n;i++){
	if(stars[2][i]<=now && stars[0][i]!=2){
	  now+=2-stars[0][i];
	  stars[0][i]=2;
	  count++;
	  flg=-1;
	}
      }

      if(flg==-1){
	flg=0;
	continue;
      }
      if(now==2*n){
	flg=1;
	break;
      }

      next=-1;
      for(i=0;i<n;i++){
	if(stars[1][i]<=now && stars[0][i]==0){
	  if(next==-1) next=i;
	  else if(stars[2][i] > stars[2][next]) next=i;
	}
      }
      if(next==-1){
	flg=2;
	break;
      }
      stars[0][next]=1;
      now++;
      count++;
      flg=0;
    }
    printf("Case #%d: ",ti);
    if(flg==1) printf("%d\n",count);
    else if(flg==2) printf("Too Bad\n");
  }
  return 0;
}
