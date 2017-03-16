#include<stdio.h>

int cnt[1000];

int main(int agrc,char*argv[]){
  int T;scanf("%d",&T);
  for(int tc=1;tc<=T;tc++){
    int R,C,W;scanf("%d%d%d",&R,&C,&W);
    int res=(C/W)*R;
    if(W>1){
      res+=W;
      if(C%W==0) res--;
    }
    printf("Case #%d: %d\n",tc,res);
  }
  return 0;
}
