#include<stdio.h>
#include<string.h>
int n;
char v[1111111];
int ct=1;
void proc(){
  scanf("%d",&n);
  scanf("%s",v);
  int i;
  int l = strlen(v);
  int sum=0;
  int ans=0;
  for(i=0;i<l;i++){
    if(sum<i){
      ans+=i-sum;
      sum=i;
    }
    sum+=v[i]-'0';
  }
  printf("Case #%d: %d\n",ct++,ans);
}
int main(){
  int qq;
  scanf("%d",&qq);
  while(qq--)proc();
  return 0;

}
