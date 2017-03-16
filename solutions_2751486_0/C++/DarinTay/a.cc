#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int n;
#define ll long long

string vow = "aeiou";

ll solve(int p) {
  ll ans = 0;
  int b = 0;
  int lm = 0;
  for (int i=0;i<s.size();++i) {
    if (vow.find(s[i]) == string::npos) {
      ++b;
      if (b >= n) {
        int inc = (i-n+2 - lm) * (s.size() - i);
        ans += inc;
        lm = i-n+2;
      }
    } else {
      b = 0;
    }
  }
  return ans;
}

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;++t) {
    cin>>s>>n;
    cout << "Case #" << t << ": " << solve(0) << endl;
  }
}
