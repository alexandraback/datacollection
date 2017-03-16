#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin>>t; for(int zz=1;zz<=t;zz++) {
    int n; cin>>n;
    int x=n;
    if(!x) goto gg;
    {
    bool seen[10];
    for(int d=0;d<10;d++) seen[d]=false;
    for(;;x+=n) {
      string s=to_string(x);
      for(char c:s) seen[c-'0']=true;
      for(int d=0;d<10;d++) if(!seen[d]) goto ct;
      goto gg;
    ct:
      continue;
    }
    }
  gg:
    if(!x) printf("Case #%d: INSOMNIA\n",zz);
    else printf("Case #%d: %d\n",zz,x);
  }
}
