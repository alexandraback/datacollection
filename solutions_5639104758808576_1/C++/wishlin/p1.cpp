#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
  int cas, len, tot, add;
  string str;

  scanf("%d",&cas);
  for (int k=1; k<=cas; ++k) {
    cin>>len>>str;
    tot=add=0;

    for (int i=0; i<=len; ++i) {
      if (str[i]=='0') continue;
      if (tot>=i) tot+=str[i]-'0';
      else {
        add+=i-tot;
        tot=i;
        tot+=str[i]-'0';
      }
    }

    printf("Case #%d: %d\n", k, add);
  }
  return 0;
}
