#include<stdio.h>

int solve(void);

int main(void){
  int t,i,ans;

  scanf("%d",&t);

  for(i=1;i<=t;i++){
    ans=solve();
    if(ans==-1) printf("Case #%d: INSOMNIA\n",i);
    else printf("Case #%d: %d\n",i,ans);
  }

  return 0;
}

int solve(void){
  int N,flg[10]={0};
  int tmp,prod=0,br;
  int i,j,k;

  scanf("%d",&N);
  for(i=0;i<1000;i++){
    prod+=N;
    tmp=prod;
    do{
      flg[tmp%10]=1;
      tmp/=10;
    }while(tmp!=0);
    for(j=br=0;j<10;j++) br+=flg[j];
    if(br==10) break;
  }

  return (br==10)?prod:-1;
}
