#include <bits/stdc++.h>

#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;

int main() {
  int t;
  cin>>t;
  REP(cnt,t) {
    string s;
    cin>>s;
    int regs = 1;
    REP(i,s.size()-1) {
      if (s[i+1] != s[i]) ++regs;
    }
    if (s.back() == '+') --regs;
    cout << "Case #" << (cnt+1) << ": " << regs << endl;
  }
  return 0;
}
