#include<stdio.h>
int i,c,d,f,n;
int main(){
scanf("%d%c",&n,&c);
for(;i++<n;){
for(f=d=0;(c=getchar())>10;d=c)f+=d!=c;
printf("Case #%d: %d\n",i,f-(d=='+'));
}
}


