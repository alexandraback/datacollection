#include<stdio.h>

int main(void){
  unsigned T,R,C,W,tt,ans;

  scanf("%u",&T);
  for(tt=1;tt<=T;tt++){
    scanf("%u%u%u",&R,&C,&W);
    ans=R*(C/W)+W-1;
    if(W!=1 && C%W!=0) ans++;
    printf("Case #%u: %u\n",tt,ans);
  }
  return 0;
}
