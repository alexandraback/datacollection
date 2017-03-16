#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int maxn = 1000 + 10;
string st;

string f(const string &st) {
  if (st == "") return "";
  char max_ch = 'A';
  for (int i = 0; i < st.length(); i++) {
    if (st[i] > max_ch) max_ch = st[i];
  }
  string ret = "";
  string prefix = "";
  int first_show = -1;
  for (int i = 0; i < st.length(); i++) {
    if (st[i] == max_ch) {
      prefix = prefix + st[i];
      if (first_show < 0) first_show = i;
    } else {
      if (first_show >= 0) ret = ret + st[i];
    }
  }
  ret = prefix + f(st.substr(0, first_show)) + ret;
  return ret;
}

int main() {
  // freopen("A-small-attempt0", "r", stdin);
  // freopen("A.out", "w", stdout);
  
  int TextN, n;
  cin >> TextN;
  for (int TT = 1; TT <= TextN; TT++) {
    cout << "Case #" << TT << ": ";
    cin >> st;
    cout << f(st) << endl;
  }

  return 0;
}