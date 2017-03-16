#include<cstdio>
int T,C,n;
void solve(int n){
  if(!n){
    puts("INSOMNIA");
    return;
  }
  int m=0,S=0;
  for(int i=1;;i++){
    m+=n;
    for(int j=m;j;j/=10)S|=1<<(j%10);
    if(S==1023){
      printf("%d\n",m);
      return;
    }
  }
}
int main(){
  scanf("%d",&T);
  for(C=1;C<=T;C++){
    scanf("%d",&n);
    printf("Case #%d: ",C);
    solve(n);
  }
  return 0;
}