#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin>>t; for(int zz=1;zz<=t;zz++) {
    string s; cin>>s;
    char cur='+'; int cnt=0;
    for(int i=s.size();--i>=0;) if(cur!=s[i]) cur=s[i],++cnt;
    printf("Case #%d: %d\n",zz,cnt);
  }
}
