#include <bits/stdc++.h>

using namespace std;

int check(int n,string s,int len) {
  reverse(s.begin(),s.end());
  for(int i = 0;i < len;i++) {
    int cc = n % 10;
    n/=10;
    char c = char(cc + '0');
    if(c ==  s[i] || s[i] == '?') continue;
    else return 0;
  }
  return 1;
}

void solve() {
  string C,J; cin>>C>>J;
  int bestc = -1,bestj = -1;
  if(C.length() == 1) {
    for(int i = 0;i < 10;i++) {
      for(int j = 0;j < 10;j++) {
        if(check(i,C,1) && check(j,J,1)) {
          if(bestc == -1) {
            bestc = i;
            bestj = j;
          }
          else if(abs(i - j) < abs(bestc - bestj)) {
            bestc = i;
            bestj = j;
          }
          else if(abs(i - j) == abs(bestc - bestj) && j < bestj) {
            bestc = i;
            bestj = j;
          }
        }
      }
    }
  }
  else if(C.length() == 2) {
    for(int i = 0;i < 100;i++) {
      for(int j = 0;j < 100;j++) {
        if(check(i,C,2) && check(j,J,2)) {
          if(bestc == -1) {
            bestc = i;
            bestj = j;
          }
          else if(abs(i - j) < abs(bestc - bestj)) {
            bestc = i;
            bestj = j;
          }
          else if(abs(i - j) == abs(bestc - bestj) && j < bestj) {
            bestc = i;
            bestj = j;
          }
        }
      }
    }
  }
  else {
    for(int i = 0;i < 1000;i++) {
      for(int j = 0;j < 1000;j++) {
        if(check(i,C,3) && check(j,J,3)) {
          if(bestc == -1) {
            bestc = i;
            bestj = j;
          }
          else if(abs(i - j) < abs(bestc - bestj)) {
            bestc = i;
            bestj = j;
          }
          else if(abs(i - j) == abs(bestc - bestj) && j < bestj) {
            bestc = i;
            bestj = j;
          }
        }
      }
    }
  }
  if(C.length() == 1)
    cout<<bestc<<' '<<bestj<<endl;
  else if(C.length() == 2) {
    if(bestc < 10) cout<<0;
    cout<<bestc<<' ';
    if(bestj < 10) cout<<0;
    cout<<bestj<<endl;
  }
  else {
    if(bestc < 10) cout<<"00";
    else if(bestc < 100) cout<<0;
    cout<<bestc<<' ';
    if(bestj < 10) cout<<"00";
    else if(bestj < 100) cout<<0;
    cout<<bestj<<endl;
  }
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
