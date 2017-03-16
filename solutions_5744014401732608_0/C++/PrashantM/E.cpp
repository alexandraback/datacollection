#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long p2[N];

int ans[55][55];

void solve() {
  int b;
  long long m; cin>>b>>m;
  m--;
  if(m >= p2[b - 2]) {
    cout<<"IMPOSSIBLE"<<endl;
    return;
  }
  long long cc = m;
  for(int i = 2;i <= b;i++) {
    for(int j = i + 1;j <= b;j++) {
      ans[i][j] = 1;
    }
  }
  int ci = b - 1;
  ans[1][b] = 1;
  for(;ci > 1;ci--) {
    ans[1][ci] = m % 2;
    m>>=1;
  }
  cout<<"POSSIBLE"<<endl;
  for(int i = 1;i <= b;i++) {
    for(int j = 1;j <= b;j++) {
      cout<<ans[i][j];
    }
    cout<<endl;
  }
}

int main() {
  p2[0] = 1;
  for(int i = 1;i <= 50;i++) {
    p2[i] = p2[i - 1] + p2[i - 1];
  }
  assert(freopen("input.txt","r",stdin));
  assert(freopen("output.txt","w",stdout));
  int t; cin>>t;
  for(int i = 1;i <= t;i++) {
    cerr<<"Executing Case #"<<i<<endl;
    cout<<"Case #"<<i<<": ";
    solve();
  }

}
