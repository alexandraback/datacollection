#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int v[1111111];
int ct=1;
int cmp (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}
int op(int t){
  int s=0;
  int i;
  for(i=0;i<n;i++)
    s+=(int)((v[i]-0.00001)/t);
  return s;
}
int max(int a,int b){
    return a>b?a:b;
}
void proc(){
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
    scanf("%d",&v[i]);
  qsort(v,n,sizeof(int),cmp);
  int ans = -1u/2;
  int j;
  int t =0;
  for(j=1000;j>0;j--){
    t=op(j)+j;
    ans=t<ans?t:ans;
  }
  printf("Case #%d: %d\n",ct++,ans);
}
int main(){
  int qq;
  scanf("%d",&qq);
  while(qq--)proc();
  return 0;
}
