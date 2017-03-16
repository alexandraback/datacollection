#include<cstdio>
int T,C,a,b,c,i;
int main(){
  scanf("%d",&T);
  for(C=1;C<=T;C++){
    scanf("%d%d%d",&a,&b,&c);
    printf("Case #%d:",C);
    for(i=1;i<=c;i++)printf(" %d",i);
    puts("");
  }
  return 0;
}