#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T,N;

int main() {
  cin>>T; for(int zz=1;zz<=T;zz++) {
    cin>>N;
    set<int> ans;
    for(int i=N*(2*N-1);--i>=0;) {
      int x; cin>>x;
      if(ans.count(x)) ans.erase(x);
      else ans.insert(x);
    }
    printf("Case #%d:",zz);
    for(int x:ans) cout<<" "<<x;
    cout<<endl;
  }
}
