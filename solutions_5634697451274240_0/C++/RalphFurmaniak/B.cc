#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  for(int ts=1; ts<=T; ts++) {
    string s;
    cin >> s;
    char cur=0;
    int cnt=0;
    for(char c: s) {
      if(c != cur) cnt++;
      cur = c;
    }
    if(s[s.size()-1]=='+') cnt--;
    cout << "Case #" << ts << ": " << cnt << endl;
  }
}
