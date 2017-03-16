#include <stdio.h>
int t,tt,i,n,tot,r;
char s[1010];
int main() {
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&n);
    scanf("%s",s);
    for (r=tot=i=0; i<=n; i++) {
      if (tot<i) {
        r+=i-tot;
        tot=i;
      }
      tot+=s[i]-'0';
    }
    printf("Case #%d: %d\n",t,r);
  }
  return 0;
}
