#include <bits/stdc++.h>
using namespace std;
int t,tt,n,i,r,was;
char s[111];
int main() {
  freopen("Bl.in","r",stdin);
  freopen("Bl.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%s",s);
    n=strlen(s); r=0;
    for (i=n-1; i>=0; i--) if (was!=t) {
      if (s[i]=='-') { was=t; r=1; }
    } else if (s[i]!=s[i+1]) r++;
    printf("Case #%d: %d\n",t,r);
    fprintf(stderr,"Case #%d\n",t);
  }
  return 0;
}
