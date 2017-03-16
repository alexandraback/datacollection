#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

map<char, map<char, string> > table;

string flip(string x) {
  if (x[0] == '-') {
    return string(1, x[1]);
  }
  return "-" + x;
}

char abso(string x) {
  if (x[0] == '-') {
    return x[1];
  }
  return x[0];
}

int sign(string x) {
  if (x[0] == '-') {
    return -1;
  }
  return 1;
}

string mult(string a, string b) {
  char x = abso(a);
  char y = abso(b);
  string t = table[x][y];
  if (sign(a)*sign(b) == -1) {
    return flip(t);
  }
  return t;
}

void init_table() {
  table['1']['1'] = "1";
  table['1']['i'] = "i";
  table['1']['j'] = "j";
  table['1']['k'] = "k";
  table['i']['1'] = "i";
  table['i']['i'] = "-1";
  table['i']['j'] = "k";
  table['i']['k'] = "-j";
  table['j']['1'] = "j";
  table['j']['i'] = "-k";
  table['j']['j'] = "-1";
  table['j']['k'] = "i";
  table['k']['1'] = "k";
  table['k']['i'] = "j";
  table['k']['j'] = "-i";
  table['k']['k'] = "-1";
}

string eleva(string x, ll p) {
  if (p == 0) {
    return "1";
  }
  string t = eleva(x, p/2);
  t = mult(t, t);
  if (p%2 != 0) {
    t = mult(t, x);
  }
  return t;
}

bool process_case() {
  int L;
  ll X;
  string S;
  cin >> L >> X >> S;
  int p = 0;
  string t = "1";
  while (p < L*X and p < 100*L and t != "i") {
    t = mult(t, string(1, S[p%L]));
    ++p;
  }
  if (t != "i") {
    return false;
  }
  t = "1";
  while (p < L*X and p < 100*L and t != "j") {
    t = mult(t, string(1, S[p%L]));
    ++p;
  }
  if (t != "j") {
    return false;
  }
  t = "1";
  while (p%L != 0) {
    t = mult(t, string(1, S[p%L]));
    ++p;
  }
  string c = "1";
  for (int i = 0; i < L; ++i) {
    c = mult(c, string(1, S[i]));
  }
  t = mult(t, eleva(c, (L*X - p)/L));
  return t == "k";
}

int main() {
  init_table();
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cout << "Case #" << cas << ": " << (process_case() ? "YES" : "NO") << endl;
  }
}
