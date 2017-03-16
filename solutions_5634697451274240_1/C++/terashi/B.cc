#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char flip(char ch) {
  if (ch == '-') return '+';
  return '-';
}

int main() {
  int nnn;
  cin >> nnn;
  for (int iii = 0; iii < nnn; ++iii) {
    int cnt = 0;
    string seq;
    cin >> seq;
    for (; seq.find('-') != string::npos; ++cnt) {
      string new_seq(seq.size(), ' ');
      int p = seq.size()-1;
      for (; seq[p] != '-'; --p) new_seq[p] = seq[p];
      if (seq[0] == '+') {
	for (int i = 0; seq[i] == '+'; ++i) seq[i] = flip(seq[i]);
	++cnt;
      }
      for (int i = 0; i <= p; ++i) new_seq[i] = flip(seq[p-i]);
      seq = new_seq;
    }
    cout << "Case #" << iii+1 << ": " << cnt << endl;
  }
}
