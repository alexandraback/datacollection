#include<stdio.h>
unsigned long long int a[10],c,x,y;
unsigned long long int n,i,j;
int main(){
 scanf("%llu",&n);
 for(;i++<n;){
  scanf("%llu",&x);
  if(!x){
   printf("Case #%llu: INSOMNIA\n",i);
   continue;
  }
  for(c=10;c;)a[--c]=0;
  for(j=1;c<10;j++)
  for(y=x*j;y;y/=10)
  c+=!a[y%10]++;
  printf("Case #%llu: %llu\n",i,x*--j);
 }
}
