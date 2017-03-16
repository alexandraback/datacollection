#include <iostream>
#include <string.h>
using namespace std;
char s[2000];
char ans[3000];
int main() {
  int T,t,i,l,head,rear;
  cin>>T;
  for(t=0;t<T;t++) {
    memset(s, 0, sizeof(s));
    memset(ans, 0, sizeof(ans));
    scanf("%s",s);
    l=(int)strlen(s);
    head=1500;
    rear=1500;
    ans[head]=s[0];
    for(i=1;i<l;i++) {
      if(s[i]<ans[head])
        ans[++rear]=s[i];
      else
        ans[--head]=s[i];
    }
    printf("Case #%d: %s\n",t+1,ans+head);
  }
  return 0;
}
