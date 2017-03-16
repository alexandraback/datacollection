#include<cstdio>
#include<cstring>
int T,C,n,i,ans;char a[200];
int main(){
  scanf("%d",&T);
  for(C=1;C<=T;C++){
    scanf("%s",a);n=strlen(a);
    a[n]='+';
    for(i=ans=0;i<n;i++)if(a[i]!=a[i+1])ans++;
    printf("Case #%d: %d\n",C,ans);
  }
  return 0;
}