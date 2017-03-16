#include<iostream>
#include<cstdio>
void work()
{
  int n;
  char s[2000];
  scanf("%d",&n);
  scanf("%s",s);
  for(int i =0; i <=n;i++)s[i]-='0';
  int tot = s[0],ans=0;
  for(int i = 1; i<=n;i++){
    if(tot >= i)
      tot+=s[i];
    else{
      ans+= i - tot;
      tot = i;
      tot += s[i];
    }
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
