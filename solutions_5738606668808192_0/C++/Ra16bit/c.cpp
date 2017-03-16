#include <bits/stdc++.h>
using namespace std;
int t,tt,n,m,x;
char s[44];
void rec(int l) {
  if (l==x-1) {
    if (m==0) return;
    printf("%s",s);
    for (int i=2; i<=10; i++) {
      long long cur=0;
      for (int j=0; j<x; j++) cur=cur*i+s[j]-'0';
      printf(" %I64d",cur);
    }
    puts("");
    m--;
    return;
  }
  s[l]=s[l+x]='0'; rec(l+1);
  if (m==0) return;
  s[l]=s[l+x]='1'; rec(l+1);
}
int main() {
  freopen("Cs.in","r",stdin);
  freopen("Cs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&m);
    printf("Case #%d:\n",t);
    x=n/2;
    s[0]=s[x-1]='1';
    s[x]=s[n-1]='1';
    rec(1);
    fprintf(stderr,"Case #%d\n",t);
  }
  return 0;
}
