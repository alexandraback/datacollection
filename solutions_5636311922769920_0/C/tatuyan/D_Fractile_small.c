#include<stdio.h>

void solve(void);

int main(void){
  int t,i;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    printf("Case #%d: ",i+1);
    solve();
  }
  return 0;
}

void solve(void){
  int i,j;
  int K,C,S;
  scanf("%d%d%d",&K,&C,&S);

  if(C==1){
    for(i=0;i<S;i++) printf("%d%c",i+1,i==S-1?'\n':' ');
  }else{
    for(i=0;i<S;i++){
      printf("%d%c",i+1+(i*K),i==S-1?'\n':' ');
    }
  }
}
