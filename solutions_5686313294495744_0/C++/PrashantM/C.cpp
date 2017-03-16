#include <bits/stdc++.h>

using namespace std;

string a[25];
string b[25];

void solve() {
  int n; cin>>n;
  for(int i = 0;i < n;i++) {
    cin>>a[i]>>b[i];
  }
  int ans = 0;
  for(int mask = 1;mask < (1<<n);mask++) {
    set<string> first;
    set<string> second;
    for(int i = 0;i < n;i++) {
      if((mask>>i) & 1);
      else {
        first.insert(a[i]);
        second.insert(b[i]);
      }
    }
    int flag = 0;
    for(int i = 0;i < n;i++) {
      if((mask>>i) & 1) {
        if(first.find(a[i]) == first.end() || second.find(b[i]) == second.end()) {
          flag = 1;
        }
      }
    }
    if(!flag) {
      ans = max(ans,__builtin_popcount(mask));
    }
  }
  cout<<ans<<endl;
}

int main() {
  assert(freopen("input.txt","r",stdin));
  assert(freopen("output.txt","w",stdout));
  int t; cin>>t;
  for(int i = 1;i <= t;i++) {
    cerr<<"Executing Case #"<<i<<endl;
    cout<<"Case #"<<i<<": ";
    solve();
  }

}
