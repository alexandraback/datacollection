#include <iostream>
using namespace std;

int main(void) {
  string s;
  int T;
  cin >> T;
  for(int ts=1; ts<=T; ts++) {
    string s; cin >> s;
    string cur;
    for(int i=0; i<s.size(); i++) {
      string s1 = s[i] + cur;
      string s2 = cur + s[i];
      if(s1 < s2) cur = s2;
      else cur = s1;
    }
    cout << "Case #" << ts << ": " << cur << endl;
  }
}
