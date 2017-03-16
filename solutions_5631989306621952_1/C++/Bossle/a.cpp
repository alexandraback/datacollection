#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long int lli;

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ": ";
    string s;
    cin >> s;
    string out(1,s[0]);
    for (int i=1; i<s.size(); ++i) {
      if (s[i] >= out[0])
        out = string(1,s[i]) + out;
      else
        out = out + string(1,s[i]);
    }
    cout << out << endl;
  }
}