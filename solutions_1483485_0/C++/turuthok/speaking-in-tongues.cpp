#include <iostream>
#include <string>

using namespace std;

char m[256];
const char* KEY = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  m[' '] = ' ';
  for (int i = 0; KEY[i]; i++) m['a'+i] = KEY[i];

  string s;
  getline(cin, s);
  int t; sscanf(s.c_str(), "%d", &t);
  for (int caseNo = 1; caseNo <= t; caseNo++) {
    getline(cin, s);
    cout << "Case #" << caseNo << ": ";
    for (int i = 0; i < s.size(); i++)
      cout << m[s[i]];
    cout << endl;
  }
  return 0;
}

