#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)

void do_case(int cn) {
  string s;
  cin >> s;
  int ops = 0;
  while(s.size() > 0 && s.back() == '+') s.pop_back();
  if (s.size() > 0) {
    FOR(i,1,s.size()) {
      if (s[i] != s[i-1]) ++ops;
    }
    ++ops;
  }
  cout << "Case #" << cn << ": " << ops << endl;
}

int main() {
  int cn;
  cin >> cn;
  FORE(i,1,cn) do_case(i);
  return 0;
}