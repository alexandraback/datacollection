#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const string t = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  int T;
  cin >> T;
  string junk;
  getline(cin, junk); // get rid of newline

  for (int i = 0; i < T; i++) {
  
    string s;
    getline(cin, s);
    for (int j = 0; j < s.length(); j++) {
      if (!isspace(s[j]))
        s[j] = t[s[j] - 'a'];
    }

    printf("Case #%d: %s\n", i + 1, s.c_str());
  }
}