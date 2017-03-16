#include <bits/stdc++.h>

using namespace std;

int n = 32;
int db = 500;
vector<string> v;

void solve() {
  for (int i=0;i<db;i++) {
    string add = "1";
    int j=i;
    for (int k=0;k<14;k++) {
      if (j%2==1) add+="1";
      else add+="0";
      j/=2;
    }
    add+="1";
    v.push_back(add);
    cout << add<<add<<" ";
    cout << "65537 43046722 4294967297 152587890626 2821109907457 33232930569602 281474976710657 1853020188851842 10000000000000001";
    cout << endl;
  }
}

int main() {
  freopen("ki.txt", "w", stdout);
  cout << "Case #1:" << endl;
  solve();
  cout<<endl;
  return 0;
}
