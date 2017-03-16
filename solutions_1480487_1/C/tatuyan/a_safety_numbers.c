#include<stdio.h>

#define MAX(x,y) (((x)>(y))?(x):(y))

int main(void){
  int t,ti,i,j,k,n;
  int s[200],sum,pass,flg,maeflg;
  long double ans[200],tmp,num;

  scanf("%d",&t);
  for(ti=1;ti<=t;ti++){
    scanf("%d",&n);
    sum=0;
    for(i=0;i<n;i++){
      scanf("%d",&s[i]);
      sum+=s[i];
    }

    maeflg=0;
    pass=n;
    num=2*(long double)sum/n;
    while(1){
      flg=k=0;
      for(i=0;i<n;i++){
	if(s[i]>=num){
	  flg++;
	  k+=s[i];
	}
      }
      if(flg==maeflg) break;
      maeflg=flg;
      pass=n-flg;
      num=(2*sum-k)/(long double)pass;
    }

    tmp=100.0/sum;
    for(i=0;i<n;i++) ans[i]=(s[i]<num)?tmp*(num-s[i]):0;
    printf("Case #%d:",ti);
    for(i=0;i<n;i++) printf(" %Lf",MAX(ans[i],0));
    putchar('\n');
  }
  return 0;
}
