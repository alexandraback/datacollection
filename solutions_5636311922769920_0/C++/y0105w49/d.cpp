#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int t; cin>>t; for(int zz=1;zz<=t;zz++) {
    int k,c,s; cin>>k>>c>>s;
    if(c*s<k) {
      printf("Case #%d: IMPOSSIBLE\n",zz);
      continue;
    }
    set<ll> ans;
    for(ll kk=k;kk>0;) {
      ll x=0;
      for(int d=0;d<c;d++) x*=k,x+=max(--kk,0LL);
      ans.insert(x);
    }
    printf("Case #%d:",zz);
    for(ll aa:ans)cout<<' '<<++aa;
    cout<<endl;
  }
}
