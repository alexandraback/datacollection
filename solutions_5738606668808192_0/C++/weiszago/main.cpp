#include <bits/stdc++.h>

using namespace std;

int n = 16;
int db = 50;
vector<string> v;

void solve() {
  for (int i=0;i<db;i++) {
    string add = "1";
    int j=i;
    for (int k=0;k<6;k++) {
      if (j%2==1) add+="1";
      else add+="0";
      j/=2;
    }
    add+="1";
    v.push_back(add);
    cout << add<<add<<" ";
    for (int k=2;k<11;k++) {
      long long szam = 1;
      for (int l=0;l<8;l++) szam*=k;
      szam+=1;
      if (k<10)cout << szam<<" ";
      else cout << szam;
    }
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
