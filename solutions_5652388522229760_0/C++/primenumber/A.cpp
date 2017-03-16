#include <bits/stdc++.h>

#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;

int main() {
  int t;
  cin>>t;
  REP(i,t) {
    int n;
    cin>>n;
    if (n == 0) {
      cout << "Case #" << (i+1) << ": " << "INSOMNIA" << endl;
      continue;
    }
    set<int> digits;
    int m = 0;
    do {
      m += n;
      string str_m = to_string(m);
      for (char c : str_m) {
        digits.insert(c-'0');
      }
    } while (digits.size() < 10);
    cout << "Case #" << (i+1) << ": " << m << endl;
  }
  return 0;
}
