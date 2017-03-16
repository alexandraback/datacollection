#include<stdio.h>
int min(int a,int b){
  return a<b?a:b;
}
void proc(int q){
  int a,b,c,k;
  scanf("%d %d %d %d",&c,&b,&a,&k);
  k=min(a,k);
  printf("Case #%d: %d\n",q+1,b*c*min(a,k));
  for(int i=0;i<b;i++){
    for(int j=0;j<c;j++){
      for(int x=0;x<k&&x<a;x++){
        int st = (i+j)%a;
        // printf("%d %d %d %d|\n",x,k,a,st);
        printf("%d %d %d\n",j+1,i+1,(x+st)%a+1);
      }
    }
  }

}
int main(){
  int q;
  scanf("%d",&q);
  for(int i=0;i<q;i++)proc(i);
  return 0;
}
