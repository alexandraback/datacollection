#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool isUpper(const string& str, char c) {
  for (char s : str) {
    if (c > s) return true;
    if (c < s) return false;
  }
  return false;
}

int main() {
  int nnn;
  cin >> nnn;
  for (int iii = 0; iii < nnn; ++iii) {
    string in;
    cin >> in;
    string out;
    for (char c : in) {
      if (isUpper(out, c)) {
	out = c + out;
      } else {
	out += c;
      }
    }
    cout << "Case #" << iii+1 << ": " << out << endl;
  }
}
