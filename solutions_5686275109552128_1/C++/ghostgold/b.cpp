#include<iostream>
#include<cstdio>
int p[2000];
int d;
void work()
{
  
  scanf("%d",&d);
  for(int i =0; i < d;i++)
    scanf("%d",&p[i]);
  int ans = 100000;
  for(int i = 1; i<=1000;i++){
    int move = 0;
    for(int j = 0; j < d;j++){
      if(p[j] > i){
	move += (p[j]-1)/i;
      }
    }
    if(ans > move + i)
      ans = move + i;
  }
  printf("%d\n",ans);
}
int main()
{
  int T;
  scanf("%d",&T);
  for(int i =1; i <=T; i++){
    printf("Case #%d: ", i);
    work();
  }
}
