#include <iostream>
#include <vector>
using namespace std;

int main() {
  string str;
//string trans = "yhesocvxduiglbkr?tnwjpfma?"; // q, z
  string trans = "yhesocvxduiglbkrztnwjpfmaq"; // q, z
  getline(cin, str);
  int i = 1;
  while (getline(cin, str)) {
    cout << "Case #" << i << ": ";
    for (int i = 0; i < str.size(); i++) {
      if (str[i] != ' ')
        cout << trans[str[i]-'a'];
      else
        cout << ' ';
    }
    cout << endl;
    i++;
  }
}

