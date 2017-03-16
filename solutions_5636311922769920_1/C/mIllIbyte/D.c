#include<stdio.h>
int main(){
 long long int t,k,c,s;
 scanf("%lld",&t);
 long long int i,j,v,p;
 for(i=0;i++<t;){
  printf("Case #%lld: ",i);
  scanf("%lld%lld%lld",&k,&c,&s);
  if(k/c+!!(k%c)>s){
   printf("IMPOSSIBLE\n");
   continue;
  }
  for(p=0;p<k&&(p?putchar(32):1);){
   for(v=j=0;j++<c;p++)v=k*v+((k<=p)?k-1:p);
   printf("%lld",v+1);
  }
  putchar(10);
 }
}

